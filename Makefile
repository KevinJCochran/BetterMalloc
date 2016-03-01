all: test.c libbm.a
	gcc -o testrun test.c libbm.a

libbm.a: my-malloc.o
	ar r libbm.a my-malloc.o

my-malloc.o: my-malloc.c my-malloc.h
	gcc -c my-malloc.c

clean:
	rm *.o
	rm ./testrun
