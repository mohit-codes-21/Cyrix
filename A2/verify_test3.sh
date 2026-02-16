#!/bin/bash
# ============================================================
# Automated verification for Cyrix lexer test3.txt output
# ============================================================

cd "$(dirname "$0")"
OUT="out3.txt"
PASS=0
FAIL=0

check() {
    local desc="$1"
    local expected="$2"
    local actual="$3"
    if [ "$expected" = "$actual" ]; then
        echo "  PASS: $desc"
        ((PASS++))
    else
        echo "  FAIL: $desc"
        echo "    Expected: $expected"
        echo "    Got:      $actual"
        ((FAIL++))
    fi
}

check_contains() {
    local desc="$1"
    local pattern="$2"
    if grep -q "$pattern" "$OUT"; then
        echo "  PASS: $desc"
        ((PASS++))
    else
        echo "  FAIL: $desc (pattern '$pattern' not found)"
        ((FAIL++))
    fi
}

check_count() {
    local desc="$1"
    local pattern="$2"
    local expected_count="$3"
    local actual_count
    actual_count=$(grep -c "$pattern" "$OUT")
    if [ "$actual_count" -ge "$expected_count" ]; then
        echo "  PASS: $desc (found $actual_count, need >= $expected_count)"
        ((PASS++))
    else
        echo "  FAIL: $desc (found $actual_count, need >= $expected_count)"
        ((FAIL++))
    fi
}

# Check sequential lines match expected
check_seq() {
    local desc="$1"
    local start_line="$2"
    shift 2
    local line=$start_line
    local all_ok=1
    for expected in "$@"; do
        actual=$(sed -n "${line}p" "$OUT")
        if [ "$expected" != "$actual" ]; then
            echo "  FAIL: $desc - line $line expected '$expected' got '$actual'"
            ((FAIL++))
            all_ok=0
        fi
        ((line++))
    done
    if [ $all_ok -eq 1 ]; then
        echo "  PASS: $desc"
        ((PASS++))
    fi
}

echo "============================================"
echo " CYRIX LEXER COMPREHENSIVE TEST VERIFICATION"
echo "============================================"
echo ""

# ---------------------------------------------------
echo "--- 1. KEYWORDS (25 total) ---"
# ---------------------------------------------------
KEYWORDS=(BREAK CASE CHAR CONTINUE DEFAULT DO DOUBLE ELSE EXTERN FLOAT FOR IF INT LONG RETURN SHORT SIZEOF STRUCT SWITCH VOID WHILE VAR FOREACH IN MATCH CONST)
line=2
for kw in "${KEYWORDS[@]}"; do
    actual=$(sed -n "${line}p" "$OUT")
    check "Keyword $kw" "$kw" "$actual"
    ((line++))
done

# ---------------------------------------------------
echo ""
echo "--- 2. IDENTIFIERS ---"
# ---------------------------------------------------
for id in x _x __x _ __ abc123 _abc_123_ aVeryLongIdentifierNameThatGoesOnAndOnForAWhile A B C; do
    check_contains "Identifier '$id'" "^IDENTIFIER: $id\$"
done

# Keyword-prefix identifiers (should NOT be keywords)
for id in breakpoint integer fortune doing whileLoop ifTrue matching constantly foreach_item invariant switchCase voidptr returning; do
    check_contains "Keyword-prefix '$id' is IDENTIFIER" "^IDENTIFIER: $id\$"
done

# ---------------------------------------------------
echo ""
echo "--- 3. INTEGER CONSTANTS ---"
# ---------------------------------------------------
for ic in "0" "1" "9" "42" "100" "999999" "10u" "10U" "10l" "10L" "10ul" "10UL" \
          "10ll" "10LL" "10ull" "10ULL" "10llu" "10LLU" \
          "00" "01" "07" "012" "0777" "012u" "012L" "012ULL" \
          "0x0" "0X0" "0xFF" "0XFF" "0xDeAdBeEf" "0x1a2b3c" \
          "0xFFu" "0xFFUL" "0xFFull" "0xFFULL"; do
    check_contains "I_CONSTANT: $ic" "^I_CONSTANT: $ic\$"
done

# Character constants
for cc in "'a'" "'z'" "'A'" "'Z'" "'0'" "'9'" "' '"; do
    check_contains "I_CONSTANT: $cc" "^I_CONSTANT: $cc\$"
done

# Escape char constants
check_contains "Char escape \\n" "^I_CONSTANT: '\\\\n'"
check_contains "Char escape \\t" "^I_CONSTANT: '\\\\t'"
check_contains "Char escape \\0" "^I_CONSTANT: '\\\\0'"
check_contains "Char escape \\\\" "^I_CONSTANT: '\\\\\\\\'"

# Prefixed char constants
check_contains "Prefixed char L'a'" "^I_CONSTANT: L'a'"
check_contains "Prefixed char u'a'" "^I_CONSTANT: u'a'"
check_contains "Prefixed char U'a'" "^I_CONSTANT: U'a'"

# ---------------------------------------------------
echo ""
echo "--- 4. FLOAT CONSTANTS ---"
# ---------------------------------------------------
for fc in "3.14" "0.5" ".5" "5." "0.0" "100.001" \
          "1e5" "1E5" "1e+5" "1e-5" "1E+10" "1E-10" "123e4" "123E4" \
          "3.14e2" ".5e10" "5.e-3" "0.0E0" \
          "3.14f" "3.14F" "3.14l" "3.14L" "1e5f" "1e5L" ".5f" "5.F" \
          "0x1.0p10" "0x1.0P10" "0x1.0p+10" "0x1.0p-10" \
          "0xA.Bp3" "0xA.Bp+3" "0xA.Bp-3" \
          "0x1p0" "0x1P0" "0x0.1p4" "0x1.p4" \
          "0x1.0p10f" "0x1.0p10L" \
          ".0" "0." ".1e1" "0.e0" "1.e+0" "1.e-0" \
          "3.14159265358979"; do
    check_contains "F_CONSTANT: $fc" "^F_CONSTANT: $fc\$"
done

# ---------------------------------------------------
echo ""
echo "--- 5. STRING LITERALS ---"
# ---------------------------------------------------
check_count "STRING_LITERAL count >= 3" "^STRING_LITERAL$" 3

# ---------------------------------------------------
echo ""
echo "--- 6. ALL OPERATORS ---"
# ---------------------------------------------------
check_contains "TH_OP (<=>) present" "^TH_OP$"
check_contains "SAFE_DOT (?.) present" "^SAFE_DOT$"
check_contains "LAMBDA_ARROW (=>) present" "^LAMBDA_ARROW$"
check_contains "POW_OP (**) present" "^POW_OP$"
check_contains "INC_OP (++) present" "^INC_OP$"
check_contains "DEC_OP (--) present" "^DEC_OP$"
check_contains "PTR_OP (->) present" "^PTR_OP$"
check_contains "AND_OP (&&) present" "^AND_OP$"
check_contains "OR_OP (||) present" "^OR_OP$"
check_contains "LE_OP (<=) present" "^LE_OP$"
check_contains "GE_OP (>=) present" "^GE_OP$"
check_contains "EQ_OP (==) present" "^EQ_OP$"
check_contains "NE_OP (!=) present" "^NE_OP$"

# Single-char operators
for op in ";" "," ":" "=" "(" ")" "." "&" "!" "~" "-" "+" "*" "/" "%" "<" ">" "^" "|" "?"; do
    check_contains "Operator '$op'" "^$(printf '%s' "$op" | sed 's/[.^$*+?{}()|[\]\\]/\\&/g')$"
done

# Braces and brackets
check_contains "Open brace {" "^{$"
check_contains "Close brace }" "^}$"
check_contains "Open bracket [" "^\[$"
check_contains "Close bracket ]" "^\]$"

# ---------------------------------------------------
echo ""
echo "--- 7. DIGRAPHS ---"
# ---------------------------------------------------
# <% and %> should produce { and }
# <: and :> should produce [ and ]
# These are already counted in the brace/bracket counts above
check_count "{ tokens (includes <% digraph)" "^{$" 10
check_count "} tokens (includes %> digraph)" "^}$" 10
check_count "[ tokens (includes <: digraph)" "^\[$" 4
check_count "] tokens (includes :> digraph)" "^\]$" 4

# ---------------------------------------------------
echo ""
echo "--- 8. OPERATOR AMBIGUITY ---"
# ---------------------------------------------------
# a<=>b should be: IDENTIFIER a, TH_OP, IDENTIFIER b
check_count "TH_OP appears multiple times" "^TH_OP$" 3

# a***b should produce POW_OP then *
# We check that POW_OP is followed by * somewhere
if awk '/^POW_OP$/{getline; if($0=="*") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: a***b produces POW_OP then *"
    ((PASS++))
else
    echo "  FAIL: a***b should produce POW_OP then *"
    ((FAIL++))
fi

# "a = > b" should produce = then > (NOT LAMBDA_ARROW)
# Check that = is immediately followed by > somewhere  
if awk '/^=$/{getline; if($0==">") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: 'a = > b' produces = then > (not LAMBDA_ARROW)"
    ((PASS++))
else
    echo "  FAIL: 'a = > b' should produce = then >"
    ((FAIL++))
fi

# "a ? . b" should produce ? then . (NOT SAFE_DOT)
if awk '/^\?$/{getline; if($0==".") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: 'a ? . b' produces ? then . (not SAFE_DOT)"
    ((PASS++))
else
    echo "  FAIL: 'a ? . b' should produce ? then ."
    ((FAIL++))
fi

# <=>> should be TH_OP then >
if awk '/^TH_OP$/{getline; if($0==">") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: '<=>' followed by '>' correctly parsed"
    ((PASS++))
else
    echo "  FAIL: '<=>' followed by '>' not correctly parsed"
    ((FAIL++))
fi

# **= should be POW_OP then =
if awk '/^POW_OP$/{getline; if($0=="=") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: '**=' produces POW_OP then ="
    ((PASS++))
else
    echo "  FAIL: '**=' should produce POW_OP then ="
    ((FAIL++))
fi

# ?.. should be SAFE_DOT then .
if awk '/^SAFE_DOT$/{getline; if($0==".") found=1} END{exit !found}' "$OUT"; then
    echo "  PASS: '?..' produces SAFE_DOT then ."
    ((PASS++))
else
    echo "  FAIL: '?..' should produce SAFE_DOT then ."
    ((FAIL++))
fi

# ---------------------------------------------------
echo ""
echo "--- 9. UNKNOWN CHARACTERS ---"
# ---------------------------------------------------
check_contains "UNKNOWN @" "^UNKNOWN: @$"
check_contains "UNKNOWN #" "^UNKNOWN: #$"
check_contains 'UNKNOWN $' '^UNKNOWN: \$$'
check_contains "UNKNOWN backtick" '^UNKNOWN: `$'
check_contains 'UNKNOWN backslash' '^UNKNOWN: \\$'

# ---------------------------------------------------
echo ""
echo "--- 10. DOT CHAIN VERIFICATION ---"
# ---------------------------------------------------
# a.b -> IDENTIFIER a, ., IDENTIFIER b
# a?.b -> IDENTIFIER a, SAFE_DOT, IDENTIFIER b  
# a?.b?.c -> IDENTIFIER a, SAFE_DOT, IDENTIFIER b, SAFE_DOT, IDENTIFIER c
check_count "SAFE_DOT occurrences" "^SAFE_DOT$" 8

# ---------------------------------------------------
echo ""
echo "--- 11. COMPLEX CONSTRUCTS ---"
# ---------------------------------------------------
check_contains "FOREACH keyword" "^FOREACH$"
check_contains "IN keyword" "^IN$"
check_contains "MATCH keyword" "^MATCH$"
check_contains "SIZEOF keyword" "^SIZEOF$"
check_contains "STRUCT keyword" "^STRUCT$"
check_contains "DO keyword" "^DO$"
check_contains "WHILE keyword" "^WHILE$"
check_contains "SWITCH keyword" "^SWITCH$"
check_contains "EXTERN keyword" "^EXTERN$"
check_contains "BREAK keyword" "^BREAK$"
check_contains "CONTINUE keyword" "^CONTINUE$"
check_contains "RETURN keyword" "^RETURN$"
check_contains "CASE keyword" "^CASE$"
check_contains "DEFAULT keyword" "^DEFAULT$"

# ---------------------------------------------------
echo ""
echo "--- 12. BOUNDARY VALUES ---"
# ---------------------------------------------------
check_contains "Large int 2147483647" "^I_CONSTANT: 2147483647$"
check_contains "Large uint 4294967295u" "^I_CONSTANT: 4294967295u$"
check_contains "Large LL 9999999999LL" "^I_CONSTANT: 9999999999LL$"
check_contains "Octal 01234567" "^I_CONSTANT: 01234567$"
check_contains "Hex 0xffffffff" "^I_CONSTANT: 0xffffffff$"
check_contains "Hex 0xFFFFFFFF" "^I_CONSTANT: 0xFFFFFFFF$"
check_contains "Hex 0x0000001" "^I_CONSTANT: 0x0000001$"

# ---------------------------------------------------
echo ""
echo "--- 13. START/END MARKERS ---"
# ---------------------------------------------------
check "First line" "Cyrix Lexer Started..." "$(head -1 "$OUT")"
check "Last line" "Cyrix Lexer Finished." "$(tail -1 "$OUT")"

# ---------------------------------------------------
echo ""
echo "============================================"
echo " RESULTS: $PASS passed, $FAIL failed"
echo "============================================"

exit $FAIL
