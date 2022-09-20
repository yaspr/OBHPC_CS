all: s0 s1 s2 s3 ss sf

s0:
	gcc -std=c99 -O0 sqrt.c -o sqrt0 -lm 

s1:
	gcc -std=c99 -O1 sqrt.c -o sqrt1 -lm

s2:
	gcc -std=c99 -O2 sqrt.c -o sqrt2 -lm

s3:
	gcc -std=c99 -O3 sqrt.c -o sqrt3 -lm

sf:
	gcc -std=c99 -Ofast sqrt.c -o sqrtf -lm

ss:
	gcc -std=c99 -Os sqrt.c -o sqrts -lm

clean:
	rm -Rf *~ sqrt?
