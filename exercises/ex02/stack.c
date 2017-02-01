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

    printf("foo %p\n", array);
    // Makes all the index values = 42
    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    // printf("foo currentindex:%d\n", i);
    // printf("foo indexvalue:%d\n", array[i]);
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("bar %p\n", array);
    // Makes all the index values equal their location index
    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }

    // for (i=0; i<SIZE; i++) {
    //     printf("bar currentindex: %d\n", i);
    //     printf("bar indexvalue: %d\n", array[i]);
    // }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        // printf("currentindex: %d\n", i); // This line is fine, it prints out the actual integers 0, 1, 2, 3, and 4
    	printf("indexvalue: %d\n", array[i]); // This line bugs me. It prints out strangely large numbers
    }
    printf("main %p\n", array);

    return 0;
}
