


#include <stdio.h>
#include <stdlib.h>

int main() {
	char c = 12;
	char b = 255;
	// int b = ~c;
	// printf("%i\n", c);
	// printf("%i\n", b);
	printf("Output = %d\n", (c^b) + 1);
	return 0;
}