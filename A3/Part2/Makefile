CC = gcc
LEX = flex
YACC = bison

LEX_SRC = cyrix.l
YACC_SRC = cyrix.y

LEX_OUT = lex.yy.c
YACC_OUT_C = cyrix.tab.c
YACC_OUT_H = cyrix.tab.h

EXEC = cyrix

TEST_DIR = tests
OUT_DIR = outputs

all: build

build:
	$(YACC) -d -v $(YACC_SRC)
	$(LEX) $(LEX_SRC)
	$(CC) $(LEX_OUT) $(YACC_OUT_C) -o $(EXEC) -lfl

test: build
	mkdir -p $(OUT_DIR)
	@for file in $(TEST_DIR)/test*.txt; do \
		num=$$(basename $$file | sed 's/[^0-9]*//g'); \
		./$(EXEC) $$file > $(OUT_DIR)/output$$num.txt 2>&1; \
	done

graph:
	$(YACC) --graph=cyrix.gv $(YACC_SRC)

png: graph
	dot -Tpng cyrix.gv -o cyrix.png

clean:
	rm -f $(LEX_OUT) $(YACC_OUT_C) $(YACC_OUT_H) cyrix.output $(EXEC) cyrix.gv cyrix.png
	rm -rf $(OUT_DIR)

rebuild: clean all