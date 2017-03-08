


#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[] = "asdfghjklzxcvbnmertyuio";
	int i;
	for (i = 0; i < sizeof(str); i++) {
		str[i] = str[i]^32;
	}

	printf("%s\n", str);
	return 0;
}