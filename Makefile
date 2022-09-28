# Generated by [MakeMake](https://github.com/hubenchang0515/makemake)

.PHONY: all install uninstall clean

all: Four-Opertations-Interpreter

install: all

uninstall:

clean:
	 rm -f ast.o executor.o lexer.o main.o parser.o strings.o token.o vector.o

Four-Opertations-Interpreter : ast.o executor.o lexer.o main.o parser.o strings.o token.o vector.o  
	gcc -o $@ $^  

ast.o: ast.c ast.h
	gcc -c ast.c -O2 -W -Wall -std=c99 

executor.o: executor.c executor.h ast.h
	gcc -c executor.c -O2 -W -Wall -std=c99 

lexer.o: lexer.c utils.h strings.h lexer.h token.h vector.h
	gcc -c lexer.c -O2 -W -Wall -std=c99 

main.o: main.c token.h lexer.h vector.h ast.h parser.h executor.h
	gcc -c main.c -O2 -W -Wall -std=c99 

parser.o: parser.c parser.h vector.h token.h ast.h utils.h
	gcc -c parser.c -O2 -W -Wall -std=c99 

strings.o: strings.c strings.h utils.h
	gcc -c strings.c -O2 -W -Wall -std=c99 

token.o: token.c token.h
	gcc -c token.c -O2 -W -Wall -std=c99 

vector.o: vector.c vector.h
	gcc -c vector.c -O2 -W -Wall -std=c99 
