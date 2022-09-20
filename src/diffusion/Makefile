all: g i c

g:
	gcc -std=c99 -g3 -Ofast -ftree-vectorize -funroll-loops flame.c diffusion.c -o diffusion_g -lm -lX11

i:
	icc -std=c99 -Ofast flame.c diffusion.c -o diffusion_i -lm -lX11

c:
	clang -std=c99 -Ofast flame.c diffusion.c -o diffusion_c -lm -lX11

clean:
	rm -Rf *~ diffusion_*
