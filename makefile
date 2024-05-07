CFLAGS= -std=c99 -g -Wall -Werror

all: program

program: calculator.c main.c
	gcc -Wall -g calculator.c main.c -o program -lm

clean:
	rm program
