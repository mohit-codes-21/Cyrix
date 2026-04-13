# A4 - Intermediate Code Generation

This folder contains Lab Assignment 4 for the CS327 Compilers course. The goal is to build a Simple language compiler front-end (Flex + Bison) that emits three-address code (quadruples), prints statement-by-statement IR, and shows symbol table snapshots.

## Build

```sh
make
```

## Test and Codegen Targets

- `make tests` — run all 16 test cases and write IR output to `outputs/outputNN.txt`.
- `make tests-asm` — generate assembly + executables for tests that compile cleanly; still writes IR output for all tests.
- `make tests-run` — run the generated executables and append the final variable dump to each `outputs/outputNN.txt`.

## Assembly Code Generation (WSL)

Assembly generation and execution are supported when running in WSL with GCC (Linux toolchain). The backend emits x86-64 (AMD64) assembly using the System V ABI. These targets are not intended for native Windows shells.These targets are intended for WSL only and use GCC in the Linux toolchain.

## Clean

- `make clean` — remove build artifacts and generated `.s/.exe` files.
- `make cleanall` — remove build artifacts, generated files, and `outputs/output*.txt`.

## Notes

- `simple.l` contains the lexer rules.
- `simple.y` contains the grammar, SDT actions, and IR emission.
- `tests/` holds input programs; `outputs/` stores outputs.
- This assignment targets a small Simple language defined by the A4 spec. It is not the full Cyrix language from earlier work; extra Cyrix constructs were intentionally removed so the compiler covers only the required Simple constructs.
