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
./cyrix test1.txt > out1.txt
```

Similarly:

```
make test2
make test3
```

---

## Clean Generated Files

```
make clean
```

Removes:

* `cyrix` executable
* `lex.yy.c`
* all `out*.txt` files

---

## Notes

* Input files must be named `testX.txt`
* Output files will be saved as `outX.txt`
* Commands must be run from the project directory.
