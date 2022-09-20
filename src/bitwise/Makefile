CC=gcc

FLAGS=-std=c99

BASENAME=bitwise

all: O0 O1 O2 O3 Os Ofast

O0:
	$(CC) $(FLAGS) -O0 $(BASENAME).c -o $(BASENAME)_O0 
O1:
	$(CC) $(FLAGS) -O1 $(BASENAME).c -o $(BASENAME)_O1 
O2:
	$(CC) $(FLAGS) -O2 $(BASENAME).c -o $(BASENAME)_O2
O3:
	$(CC) $(FLAGS) -O3 $(BASENAME).c -o $(BASENAME)_O3 
Os:
	$(CC) $(FLAGS) -Os $(BASENAME).c -o $(BASENAME)_Os 
Ofast:
	$(CC) $(FLAGS) -Ofast $(BASENAME).c -o $(BASENAME)_Of

clean:
	rm -Rf *~ $(BASENAME)_O?
