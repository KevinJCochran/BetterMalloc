all: test.c libbm.a
	gcc -o testrun test.c libbm.a

libbm.a: mymalloc.o
	ar r libbm.a mymalloc.o

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c mymalloc.c

clean:
	rm *.o
	rm ./testrun
