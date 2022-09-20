all:  f k0 k1 k2 k3 k0f k2f

f:
	gfortran sum.f90 -o sum

k0:
	gcc -std=c99 -O0 kahan.c -o kahan0

k1:
	gcc -std=c99 -O1 kahan.c -o kahan1

k2:
	gcc -std=c99 -O2 kahan.c -o kahan2

k3:
	gcc -std=c99 -O3 kahan.c -o kahan3

k0f:
	gcc -std=c99 -O0 -ffast-math kahan.c -o kahan0f

k2f:
	gcc -std=c99 -O2 -ffast-math kahan.c -o kahan2f

clean:
	rm -Rf *~ kahan0 kahan1 kahan2 kahan3 kahan0f kahan2f sum

