all: test0 test1 test2 test3 test4

test0: test0.c libbm.a
	gcc -o test0 test0.c libbm.a

test1: test1.c libbm.a
	gcc -o test1 test1.c libbm.a
	
test2: test2.c libbm.a
	gcc -o test2 test2.c libbm.a

test3: test3.c libbm.a
	gcc -o test3 test3.c libbm.a

test4: test4.c libbm.a
	gcc -o test4 test4.c libbm.a

libbm.a: mymalloc.o
	ar r libbm.a mymalloc.o

mymalloc.o: mymalloc.c mymalloc.h
	gcc -c mymalloc.c

clean:
	rm *.o
