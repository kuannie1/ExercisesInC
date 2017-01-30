/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);
    // Makes all the index values = 42
    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);
    // Makes all the index values equal their location index
    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    // int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
    printf("currentindex: %d\n", i);
	printf("%d\n", array[i]);
    }

    return 0;
}
