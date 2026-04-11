# ═══════════════════════════════════════════════════
#  Simple Language Compiler — Makefile
#  CS327 Compilers — Lab Assignment #4
# ═══════════════════════════════════════════════════

CC      = gcc
CFLAGS  = -Wall -Wno-unused-function -g
TARGET  = simple
TESTS   = tests
OUTPUTS = outputs

.PHONY: all clean tests help

# ── Default: build the compiler ──────────────────
all: $(TARGET)
	@echo "✓ Build successful: ./$(TARGET)"

simple.tab.c simple.tab.h: simple.y
	bison -d -v --warnings=all simple.y -o simple.tab.c

lex.yy.c: simple.l simple.tab.h
	flex simple.l

$(TARGET): lex.yy.c simple.tab.c simple.tab.h
	$(CC) $(CFLAGS) -o $(TARGET) simple.tab.c lex.yy.c -lfl
	@echo "✓ Linked: $(TARGET)"

# ── Run all test cases ────────────────────────────
tests: $(TARGET)
	@mkdir -p $(OUTPUTS)
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  Running all 16 test cases"
	@echo "═══════════════════════════════════════"
	@for i in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16; do \
		echo ""; \
		echo "── Test $$i ──────────────────────────"; \
		if ./$(TARGET) $(TESTS)/test$$i.c > $(OUTPUTS)/output$$i.txt 2>&1; then \
			echo "  ✓ test$$i.c passed — output in $(OUTPUTS)/output$$i.txt"; \
		else \
			echo "  ✗ test$$i.c finished (check $(OUTPUTS)/output$$i.txt for details)"; \
		fi; \
	done
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  All tests done."
	@echo "═══════════════════════════════════════"

# ── Run a single test: make run FILE=tests/test01.c ──
run: $(TARGET)
	@if [ -z "$(FILE)" ]; then echo "Usage: make run FILE=tests/testNN.c"; exit 1; fi
	./$(TARGET) $(FILE)

# ── Clean build artifacts ─────────────────────────
clean:
	rm -f $(TARGET) lex.yy.c simple.tab.c simple.tab.h simple.output
	@echo "✓ Build artifacts removed"

# ── Clean outputs too ─────────────────────────────
cleanall: clean
	rm -f $(OUTPUTS)/output*.txt
	@echo "✓ Output files removed"

# ── Help ─────────────────────────────────────────
help:
	@echo ""
	@echo "  make          — build the compiler"
	@echo "  make tests    — build + run all 16 test cases"
	@echo "  make run FILE=tests/testNN.c  — run one test"
	@echo "  make clean    — remove build artifacts"
	@echo "  make cleanall — remove build artifacts + outputs"
	@echo ""
