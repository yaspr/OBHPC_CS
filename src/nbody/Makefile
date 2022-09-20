all: s0 #s1 s2 s3 ss sf

s0:
	gcc -std=c99 -O0 nbody.c -o nbody0 -lm -lSDL2 

s1:
	gcc -std=c99 -O1 nbody.c -o nbody1 -lm

s2:
	gcc -std=c99 -O2 nbody.c -o nbody2 -lm

s3:
	gcc -std=c99 -O3 nbody.c -o nbody3 -lm

sf:
	gcc -std=c99 -Ofast nbody.c -o nbodyf -lm

ss:
	gcc -std=c99 -Os nbody.c -o nbodys -lm

clean:
	rm -Rf *~ nbody?
