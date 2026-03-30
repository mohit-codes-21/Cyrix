# Part 2: Conflict Identification and Resolution

## Overview

Part 1 of the Cyrix LALR(1) parser contained **87 total conflicts** (81 shift/reduce + 6 reduce/reduce). This part documents each conflict category, explains why each occurs, and shows how the grammar was modified to eliminate **all 87 conflicts** — producing a conflict-free LALR(1) parser.

---

## Build and Run

```bash
make              # Build the parser
make test         # Run all test cases
python3 make_pt.py   # Generate the parsing table CSV
```

### Verify zero conflicts
```bash
bison -d -v cyrix.y 2>&1 | grep -E "conflict|warning"
# (no output = zero conflicts)
```

---

## Conflict Inventory

### Summary

| Category | Type | Count | States | Resolution |
|----------|------|-------|--------|------------|
| Operator precedence pass-throughs | S/R | 55 | 105,108-119,310-325 | `%left`/`%right` + `%prec` |
| Assignment operator ambiguity | S/R | 11 | 149 | `%right '='` precedence |
| Dangling else | S/R | 1 | 517 | `%nonassoc` + `%prec` |
| ATOMIC dual role | S/R | 1 | 28 | Remove from `type_qualifier` |
| Parameter list comma | S/R | 3 | 254,255,451 | Merge parameter lists |
| Lambda body comma | S/R | 2 | 395,467 | Use `assignment_expression` |
| Lambda vs expression | R/R | 2 | 164 | `fn` keyword prefix |
| Multi-assignment vs expression | R/R | 4 | 214,434 | Remove multi-assignment |
| **Total** | | **87** (81 S/R + 6 R/R) | | |

---

## Conflict Details and Resolutions

### 1. Operator Precedence Pass-Through Conflicts (55 S/R)

**Conflict:** The expression grammar uses a non-terminal hierarchy for operator precedence (e.g., `additive_expression → multiplicative_expression → power_expression → ...`). Each level has a "pass-through" rule like:

```
additive_expression : multiplicative_expression ;
```

When the parser reduces `multiplicative_expression` and sees `*` as lookahead, it faces a conflict:
- **Reduce** `multiplicative_expression` to `additive_expression` (pass-through)
- **Shift** `*` to continue matching `multiplicative_expression '*' power_expression`

This occurs at every level of the hierarchy with each relevant operator.

**Example states:** State 110 (`additive→multiplicative` vs `*`,`/`,`%`), State 111 (`shift→additive` vs `+`,`-`), State 113 (`equality→relational` vs `<`,`>`,`<=`,`>=`,`<=>`), etc.

**Resolution:** Added Bison precedence/associativity declarations and `%prec` directives:

```bison
%left '+' '-'
%left '*' '/' '%'
%right POW_OP
...

multiplicative_expression
    : power_expression %prec LOWER_THAN_ELSE  /* pass-through gets lowest precedence */
    | multiplicative_expression '*' power_expression
    ;
```

With `%prec LOWER_THAN_ELSE` (the lowest precedence), the shift always wins over the pass-through reduce — without being reported as a conflict.

---

### 2. Assignment Operator Ambiguity (11 S/R)

**Conflict (State 149):** After parsing a `unary_expression`, the pass-through `cast_expression → unary_expression` competes with shifting an assignment operator (`=`, `+=`, `-=`, etc.) for `assignment_expression → unary_expression assignment_operator assignment_expression`.

**Resolution:** Declared assignment operators as right-associative with `%right`:

```bison
%right '=' MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN
       LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
```

The `%prec LOWER_THAN_ELSE` on `cast_expression → unary_expression` gives the reduce lower precedence than any assignment operator, so shift wins cleanly.

---

### 3. Dangling Else (1 S/R)

**Conflict (State 517):** The classic ambiguity with nested `if` statements:

```c
if (a) if (b) s1; else s2;
```

The `else` could bind to either `if`. The parser has:
- **Reduce** `IF '(' expression ')' statement` (bind `else` to outer `if`)
- **Shift** `ELSE` (bind to inner `if` — standard C behavior)

**Resolution:** Used `%nonassoc` precedence levels:

```bison
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

selection_statement
    : IF '(' expression ')' statement ELSE statement
    | IF '(' expression ')' statement %prec LOWER_THAN_ELSE
    ;
```

The `if`-without-`else` rule gets `LOWER_THAN_ELSE` precedence, which is lower than `ELSE`. Bison chooses shift (binding `else` to nearest `if`).

**Before (Part 1):** Ambiguous — Bison silently chose shift (correct behavior, but reported as conflict).

**After (Part 2):** Explicitly resolved via precedence. Same parsing behavior, zero conflicts.

**Test (test6_dangling_else.txt):**
```c
int main() {
    int x = 10;
    int y = 20;
    if (x > 5)
        if (y > 10)
            x = 1;
        else
            x = 2;   // binds to inner if (y > 10)
    return x;
}
```

---

### 4. ATOMIC Dual Role (1 S/R)

**Conflict (State 28):** The token `ATOMIC` appeared in two roles:

```bison
type_qualifier : ATOMIC ;                        /* standalone qualifier */
atomic_type_specifier : ATOMIC '(' type_name ')' ; /* type specifier */
```

When `ATOMIC` is followed by `(`, the parser cannot decide:
- **Reduce** `ATOMIC` to `type_qualifier`
- **Shift** `(` to start matching `atomic_type_specifier`

**Resolution:** Removed `ATOMIC` from `type_qualifier`. The `_Atomic` keyword is only used as `_Atomic(type)` (atomic type specifier), not as a standalone qualifier.

```bison
type_qualifier
    : CONST
    | RESTRICT
    | VOLATILE
    /* ATOMIC removed */
    ;
```

---

### 5. Parameter List Comma Ambiguity (3 S/R)

**Conflict (States 254, 255, 451):** The original grammar split parameters into `normal_param_list` and `default_param_list`:

```bison
parameter_list
    : normal_param_list
    | normal_param_list ',' default_param_list
    | default_param_list
    ;
```

After `normal_param_list`, seeing `,`, the parser cannot decide:
- **Reduce** and then shift `,` for `normal_param_list ',' default_param_list`
- **Shift** `,` to continue `normal_param_list ',' normal_param`

**Resolution:** Merged into a unified `parameter_list` with `param_declaration` that accepts both normal and default parameters:

```bison
parameter_list
    : param_declaration
    | parameter_list ',' param_declaration
    ;

param_declaration
    : declaration_specifiers declarator
    | declaration_specifiers abstract_declarator
    | declaration_specifiers
    | declaration_specifiers declarator '=' assignment_expression  /* default param */
    ;
```

**Test (test9_default_params.txt):**
```c
int add(int a, int b = 10) {
    return a + b;
}
```

---

### 6. Lambda Body Comma (2 S/R)

**Conflict (States 395, 467):** Lambda body used `expression`, which includes the comma operator:

```bison
lambda_expression : '(' ')' LAMBDA_ARROW expression ;
```

After parsing `fn() => expr`, seeing `,` was ambiguous:
- **Reduce** the lambda (end of lambda body)
- **Shift** `,` to extend `expression → expression ',' assignment_expression`

**Resolution:** Changed lambda body from `expression` to `assignment_expression`:

```bison
lambda_expression
    : FN '(' ')' LAMBDA_ARROW assignment_expression
    | FN '(' lambda_params ')' LAMBDA_ARROW assignment_expression
    ;
```

This is the same approach used by C++ lambdas — the comma operator is not part of the lambda body unless wrapped in parentheses.

---

### 7. Lambda vs Expression Ambiguity (2 R/R) — **REDUCE-REDUCE**

**Conflict (State 164):** The original grammar used `(params) => expr` for lambdas:

```bison
lambda_expression : '(' lambda_params ')' LAMBDA_ARROW expression ;
lambda_params     : IDENTIFIER ;
primary_expression: IDENTIFIER ;
primary_expression: '(' expression ')' ;
```

After `( IDENTIFIER`, the parser has a **reduce-reduce conflict**:
- **Reduce** `IDENTIFIER` to `lambda_params` (start of lambda)
- **Reduce** `IDENTIFIER` to `primary_expression` (start of parenthesized expression)

Both are valid reductions, and the parser cannot decide without unbounded lookahead.

**Resolution:** Introduced the `fn` keyword to prefix lambda expressions:

```bison
lambda_expression
    : FN '(' ')' LAMBDA_ARROW assignment_expression
    | FN '(' lambda_params ')' LAMBDA_ARROW assignment_expression
    | FN '(' ')' LAMBDA_ARROW compound_statement
    | FN '(' lambda_params ')' LAMBDA_ARROW compound_statement
    ;
```

Now `(IDENTIFIER` always starts a parenthesized expression, and `FN(` always starts a lambda. No ambiguity.

**Before (Part 1):**
```c
int x = (a, b) => a + b;   // ambiguous: lambda or expression?
```

**After (Part 2):**
```c
int x = fn(a, b) => a + b;  // unambiguous: fn keyword marks lambda
```

**Test (test7_lambda.txt):**
```c
int main() {
    int x = fn(a, b) => a + b;
    int y = fn() => 42;
    return x;
}
```

---

### 8. Multi-Assignment vs Expression Ambiguity (4 R/R) — **REDUCE-REDUCE**

**Conflict (States 214, 434):** The grammar supported multi-assignment `a, b = x, y`:

```bison
lhs_list          : IDENTIFIER ;
primary_expression: IDENTIFIER ;
multi_assignment  : lhs_list '=' rhs_list ;
```

After `IDENTIFIER`, on seeing `,` or `=`, the parser had a **reduce-reduce conflict**:
- **Reduce** to `primary_expression` (start of an expression)
- **Reduce** to `lhs_list` (start of multi-assignment)

Bison also flagged `lhs_list: IDENTIFIER` as a **useless rule** because the default resolution always chose `primary_expression`.

**Resolution:** Removed multi-assignment entirely. Single assignments still work via:
```bison
assignment_expression: unary_expression assignment_operator assignment_expression ;
```

Regular `a = 5;` continues to parse correctly. The multi-assignment feature (`a, b = x, y`) was fundamentally incompatible with the LALR(1) parsing strategy.

**Before (Part 1):**
```c
a, b = x, y;  // ambiguous: multi-assignment or comma expression?
// Bison always chose expression interpretation anyway (rule was useless)
```

**After (Part 2):**
```c
a = x;  // regular assignment — works
b = y;  // regular assignment — works
```

---

## Grammar Changes Summary

| Change | Lines Modified | Rules Removed | Rules Added |
|--------|---------------|---------------|-------------|
| Precedence declarations | Token section | 0 | 16 `%left`/`%right`/`%nonassoc` |
| `%prec` on pass-throughs | 14 rules | 0 | 14 `%prec` directives |
| Lambda `fn` prefix | 4 rules | 0 | `FN` token + lexer rule |
| Remove multi-assignment | expression_statement | 5 rules (`lhs_list`, `rhs_list`, `multi_assignment`) | 0 |
| Remove ATOMIC qualifier | type_qualifier | 1 alternative | 0 |
| Merge parameter lists | parameter rules | 5 rules | 2 rules |
| Dangling else `%prec` | selection_statement | 0 | 1 `%prec` directive |
| Lambda body type | lambda_expression | 0 | Changed `expression` → `assignment_expression` |

---

## Verification

```
Before (Part 1): 81 shift/reduce conflicts, 6 reduce/reduce conflicts
After  (Part 2):  0 shift/reduce conflicts, 0 reduce/reduce conflicts
```

The parsing table (parsing_table.csv) contains **no conflict cells** (no `/` separator in any cell).

---

## Test Cases

| Test | Description | Expected |
|------|-------------|----------|
| test1.txt | Basic main function | Success |
| test2.txt | Simple declaration with arithmetic | Success |
| test3.txt | Function with declarations | Success |
| test4.txt | Syntax error (missing semicolon) | Error at `}` |
| test5.txt | Deep nesting | Success |
| test6_dangling_else.txt | Nested if-else (dangling else) | Success |
| test7_lambda.txt | Lambda with `fn` keyword | Success |
| test8_operators.txt | All operator precedence levels | Success |
| test9_default_params.txt | Default parameter values | Success |
| test10_complex.txt | Full program (structs, loops, switch, var) | Success |
| test11_error.txt | Missing semicolon error | Error at `return` |
| test12_foreach_match.txt | Foreach loop and match statement | Success |
