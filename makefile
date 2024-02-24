
FLAG=-Wall -g

all: prog

clean: rm -f o.* prog

StrList.o  :StrList.c StrList.h
	gcc $(FLAG) -C StrList.c StrList.h -o StrList.o

main.o: main.c
	gcc $(FLAG) -C main.c -o main.o

prog: StrList.o main.o
	gcc $(FLAG) StrList.o main.o -o prog


