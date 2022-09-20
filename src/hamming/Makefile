all:
	gcc -std=c99 -march=native -Ofast -fopenmp -funroll-loops -finline-functions -ftree-vectorize -g3 hamming.c -o hamming -lm

clean:
	rm -Rf *~ hamming
