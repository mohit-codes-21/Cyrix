# Cyrix Compiler (Flex and Bison)

## Overview

This project implements a compiler front-end using Flex for lexical analysis and Bison for syntax analysis. The system reads an input source file, performs tokenization and parsing, and reports whether the input conforms to the specified grammar.

---

## Prerequisites

Ensure the following tools are installed:

```bash
flex --version
bison --version
gcc --version
dot -V
```

If required, install using:

```bash
sudo apt install flex bison gcc graphviz
```

---

## File Structure

```
cyrix.l        Lexer specification (Flex)
cyrix.y        Parser specification (Bison)
test.c         Sample input file
```

---

## Build Instructions

### Step 1: Generate parser

```bash
bison -d -v cyrix.y
```

Generated files:

```
cyrix.tab.c
cyrix.tab.h
cyrix.output
```

---

### Step 2: Generate lexer

```bash
flex cyrix.l
```

Generated file:

```
lex.yy.c
```

---

### Step 3: Compile

```bash
gcc lex.yy.c cyrix.tab.c -o cyrix -lfl
```

Generated executable:

```
cyrix
```

---

## Execution

Run the compiler on an input file:

```bash
./cyrix test.c
```

---

## Output

* On successful parsing:

```
***parsing successful***
```

* On syntax error:

```
***parsing terminated*** [syntax error]
```

---

## Notes

* The input file must be provided as a command-line argument.
* Standard input redirection is not supported.

---

## Generating Parser State Information

To inspect parser states and conflicts:

```bash
bison -d -v cyrix.y
```

Output file:

```
cyrix.output
```

---

## Generating Graph Representation

To generate a graph description of the parser:

```bash
bison --graph=cyrix.gv cyrix.y
```

Generated file:

```
cyrix.gv
```

---

## Converting Graph to Image

To convert the graph into a PNG image:

```bash
dot -Tpng cyrix.gv -o cyrix.png
```

Generated file:

```
cyrix.png
```

---

## Complete Build and Run Sequence

```bash
bison -d -v cyrix.y
flex cyrix.l
gcc lex.yy.c cyrix.tab.c -o cyrix -lfl
./cyrix test.c
```

---
## Using Makefile

A Makefile is provided to automate the build, testing, and cleanup process.

---

### Build using Make

```bash
make
```

This performs:

* Parser generation using Bison
* Lexer generation using Flex
* Compilation using GCC

---

### Run all test cases

Test files must be placed in the `tests/` directory with names of the form:

```
test1.txt, test2.txt, ...
```

Run:

```bash
make test
```

This will:

* Execute the compiler on each test file
* Store outputs in the `outputs/` directory as:

```
output1.txt, output2.txt, ...
```

---

### Generate parser graph

```bash
make graph
```

Generates:

```
cyrix.gv
```

---

### Convert graph to image

```bash
make png
```

Generates:

```
cyrix.png
```

---

### Clean generated files

```bash
make clean
```

Removes:

* Generated parser and lexer files
* Executable
* Output directory
* Graph files

---

### Rebuild

```bash
make rebuild
```

Performs:

* Clean
* Fresh build

---

## Summary of Commands

| Task            | Command                                  |
| --------------- | ---------------------------------------- |
| Generate parser | `bison -d -v cyrix.y`                    |
| Generate lexer  | `flex cyrix.l`                           |
| Compile         | `gcc lex.yy.c cyrix.tab.c -o cyrix -lfl` |
| Run             | `./cyrix test.c`                         |
| Generate graph  | `bison --graph=cyrix.gv cyrix.y`         |
| Convert to PNG  | `dot -Tpng cyrix.gv -o cyrix.png`        |

---
