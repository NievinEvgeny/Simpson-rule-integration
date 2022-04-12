all: Integration.c
		gcc -Wall -o bin $^ -lm
clean:
		rm bin