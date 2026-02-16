LEX = flex
CC = gcc
TARGET = cyrix

all: $(TARGET)

$(TARGET): cyrix.l
	$(LEX) cyrix.l
	$(CC) lex.yy.c -o $(TARGET) -lfl

# Run test files: make test1, make test2, etc.
test%: $(TARGET)
	./$(TARGET) test$*.txt > out$*.txt

clean:
	rm -f lex.yy.c $(TARGET) 
