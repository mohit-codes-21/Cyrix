# Cyrix Lexer – README

## Requirements

* Linux / WSL / macOS terminal
* `flex` installed
* `gcc` installed

---

## Files

* `cyrix.l` → Lexer specification
* `Makefile` → Build & run automation
* `testX.txt` → Input test files
* `outX.txt` → Generated outputs

---

## Build the Lexer

```
make
```

This will:

* Run `flex` on `cyrix.l`
* Compile the generated C file
* Create executable `cyrix`

---

## Run Test Files

To run a test file and save output:

```
make test1
```

This executes:

```
./cyrix tests/test1.txt > outputs/out1.txt
```

Similarly:

```
make test2
make test3
```

For a test file with any other name, you'll have to manually run the command:

```
./cyrix tests/your_test_file.txt > outputs/your_output_file.txt
```

---

## Clean Generated Files

```
make clean
```

Removes:

* `cyrix` executable
* `lex.yy.c`

---

## Notes

* Input files must be named `testX.txt` in the `tests` directory.
* Output files will be saved as `outX.txt` in the `outputs` directory.
* Commands must be run from the project directory.
