CC=gcc --std=c99 -g

all: list-sort pointers array-sort

list-sort: buggy-list-sort.c
	$(CC) buggy-list-sort.c -g -o list-sort

pointers: buggy-pointers.c
	$(CC) buggy-pointers.c -g -o pointers

array-sort: buggy-array-sort.c
	$(CC) buggy-array-sort.c -g -o array-sort

clean:
	rm -f *.o list-sort pointers array-sort
