/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    // allocates space in the foo stack for the integer i and the array of size 5
    int i;
    int array[SIZE];
    //Original print statement
//    // int *array = malloc(SIZE * sizeof(int));

    //prints the memory address of this array
    printf("foo %p\n", array);
    
    // for loop makes all the index values = 42
    for (i=0; i<SIZE; i++) {
	   array[i] = 42;
       //print statements for my testing:
//    // printf("foo currentindex:%d\n", i);
//    // printf("foo indexvalue:%d\n", array[i]);
    }
    //Returns the pointer to the 42 42 42 42 42 array
    return array;
}

void bar() {
    // allocates space in the foo stack for the integer i and the array of size 5
    int i;
    int array[SIZE];

    //Original print statement
//    // printf("bar %p\n", array);
    
    // Makes each space in the array equal their location index
    for (i=0; i<SIZE; i++) {
	   array[i] = i;
    }
}

int main()
{
    //Allocates space for the integer i and an array pointer, which calls the foo() method
    int i;
    int *array = foo();
    //the foo() method terminates, bar operates on the space allocated to foo()
    bar();

    // With the array originally allocated to foo(), then bar(), print each element of the array 
    for (i=0; i<SIZE; i++) {
        // printf("currentindex: %d\n", i); // This line is fine, it prints out the actual integers 0, 1, 2, 3, and 4
    	printf("%d\n", array[i]); // This line bugs me. It prints out strange large numbers and zeroes
    }
    printf("main %p\n", array); //My printing test, prints the address of final main() array

    return 0;
}