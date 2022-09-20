CC = gcc

CFLAGS = -std=c99 -g3

LFLAGS = -lm

OFLAGS = -O3

all: cholesky

cholesky: cholesky.c
	$(CC) $(CFLAGS) $(OFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm -Rf *~ cholesky
