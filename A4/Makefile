# ═══════════════════════════════════════════════════
#  Simple Language Compiler — Makefile
#  CS327 Compilers — Lab Assignment #4
# ═══════════════════════════════════════════════════

CC      = gcc
CFLAGS  = -Wall -Wno-unused-function -g
TARGET  = simple
TESTS   = tests
OUTPUTS = outputs

.PHONY: all clean tests asm runasm tests-asm tests-run help

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

# ── Generate assembly + executable for a single file ──
asm: $(TARGET)
	@if [ -z "$(FILE)" ]; then echo "Usage: make asm FILE=tests/testNN.c"; exit 1; fi
	@./$(TARGET) $(FILE)
	@gcc $(FILE:.c=.s) -o $(FILE:.c=.exe)
	@echo "✓ Built: $(FILE:.c=.exe)"

# ── Generate assembly, build, and run (append output) ──
runasm: asm
	@OUT=$(OUTPUTS)/$(notdir $(FILE:.c=.txt)); \
	if [ -f "$(FILE:.c=.exe)" ]; then \
		./$(FILE:.c=.exe) >> $$OUT; \
		echo "  ✓ appended execution output to $$OUT"; \
	else \
		echo "  ✗ no executable generated; output file unchanged"; \
	fi

# ── Build assembly for all tests ───────────────────
tests-asm: $(TARGET)
	@mkdir -p $(OUTPUTS)
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  Generating assembly for all tests"
	@echo "═══════════════════════════════════════"
	@for i in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16; do \
		echo ""; \
		echo "── Test $$i ──────────────────────────"; \
		TMP=$(OUTPUTS)/.tmp_output$$i.txt; \
		OK=$(OUTPUTS)/test$$i.ok; \
		rm -f $$OK $(TESTS)/test$$i.exe; \
		./$(TARGET) $(TESTS)/test$$i.c > $$TMP 2>&1; \
		STATUS=$$?; \
		mv $$TMP $(OUTPUTS)/output$$i.txt; \
		if [ $$STATUS -eq 0 ]; then \
			if gcc $(TESTS)/test$$i.s -o $(TESTS)/test$$i.exe; then \
				touch $$OK; \
				echo "  ✓ test$$i.c asm+exe built"; \
			else \
				rm -f $(TESTS)/test$$i.exe; \
				echo "  ✗ test$$i.c gcc failed"; \
			fi; \
		else \
			echo "  ✓ test$$i.c IR generated (errors reported)"; \
		fi; \
	done
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  Assembly build done."
	@echo "═══════════════════════════════════════"

# ── Build + run assembly for all tests (append output) ──
tests-run: tests-asm
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  Running all test executables"
	@echo "═══════════════════════════════════════"
	@for i in 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16; do \
		echo ""; \
		echo "── Test $$i ──────────────────────────"; \
		if [ -f "$(OUTPUTS)/test$$i.ok" ]; then \
			./$(TESTS)/test$$i.exe >> $(OUTPUTS)/output$$i.txt 2>&1; \
			rm -f $(OUTPUTS)/test$$i.ok; \
			echo "  ✓ test$$i.exe ran — output appended"; \
		fi; \
	done
	@echo ""
	@echo "═══════════════════════════════════════"
	@echo "  Execution done."
	@echo "═══════════════════════════════════════"

# ── Run a single test: make run FILE=tests/test01.c ──
run: $(TARGET)
	@if [ -z "$(FILE)" ]; then echo "Usage: make run FILE=tests/testNN.c"; exit 1; fi
	./$(TARGET) $(FILE)

# ── Clean build artifacts ─────────────────────────
clean:
	rm -f $(TARGET) lex.yy.c simple.tab.c simple.tab.h simple.output
	rm -f $(TESTS)/*.s $(TESTS)/*.exe
	rm -f $(OUTPUTS)/*.ok
	@echo "✓ Build artifacts removed"

# ── Clean outputs too ─────────────────────────────
cleanall: clean
	rm -f $(TARGET) lex.yy.c simple.tab.c simple.tab.h simple.output
	@echo "✓ Build artifacts removed"
	rm -f $(OUTPUTS)/output*.txt
	rm -f $(TESTS)/*.s $(TESTS)/*.exe
	rm -f $(OUTPUTS)/*.ok
	@echo "✓ Outputs removed"

# ── Help ─────────────────────────────────────────
help:
	@echo ""
	@echo "  make          — build the compiler"
	@echo "  make tests    — build + run all 16 test cases (IR only)"
	@echo "  make asm FILE=tests/testNN.c     — generate .s + .exe for one test"
	@echo "  make runasm FILE=tests/testNN.c  — build + run one test (append output)"
	@echo "  make tests-asm — generate .s + .exe for all tests"
	@echo "  make tests-run — run all .exe and append output"
	@echo "  make run FILE=tests/testNN.c  — run one test"
	@echo "  make clean    — remove build artifacts"
	@echo "  make cleanall — remove build artifacts + outputs"
	@echo ""
