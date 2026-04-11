# A4 - Intermediate Code Generation

This folder contains Lab Assignment 4 for the CS327 Compilers course. The goal is to build a Simple language compiler front-end (Flex + Bison) that emits three-address code (quadruples), prints statement-by-statement IR, and shows symbol table snapshots.

## Build

```sh
make
```

## Run a Single Test

```sh
make run FILE=tests/test01.c
```

## Run All Tests

```sh
make tests
```

## Clean

```sh
make clean
```

## Notes

- `simple.l` contains the lexer rules.
- `simple.y` contains the grammar, SDT actions, and IR emission.
- `tests/` holds input programs; `outputs/` stores expected outputs.
- This assignment targets a small Simple language defined by the A4 spec. It is not the full Cyrix language from earlier work; extra Cyrix constructs were intentionally removed so the compiler covers only the required Simple constructs.
