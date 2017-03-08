/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int global;

void print_local() {
	int localvar = 0;
	printf ("Address of this local variable is %p\n", &localvar);
}

int main ()
{
    int local = 5;
    void *p = malloc(128);
    void *d = malloc(50);

	void *a = malloc(16);
	void *b = malloc(24);


    printf ("Address of main is %p\n", main); // address of first machine language instruction in main
    printf ("Address of global is %p\n", &global); // a global variable in static segment
    printf ("Address of local is %p\n", &local); // local variable, so stack? 
    
    print_local();

    printf ("Address of p is %p\n", p); // address returned by malloc, allocates space in heap,
    printf ("Address of d is %p\n", d); // address is higher than heap address --> heap grows upward. 
    
    printf ("Address of a is %p\n", a);
    printf ("Address of b is %p\n", b);
    printf ("difference is %p\n", b - a);


    return 0;
}
