CC      = cc
CFLAGS  = -std=c99 -Wall -Wextra -O3 -maes -march=native

all: tests/tests

tests/tests: tests/tests.c aes128ni.h
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ tests/tests.c $(LDLIBS)

check: tests/tests
	tests/tests

clean:
	rm -f tests/tests
