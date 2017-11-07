all: test

CFLAGS = -g -O2

test: test.o mytok.o
	cc -o test test.o mytok.o mytok.h
	cc -c mytok.c mytok.h
clean:
	rm -f *.o *.gch test test.exe
