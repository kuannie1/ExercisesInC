/* 

tee command

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	char line[80];  //The input line
	// attempt to save contents of stdout into a file
	FILE *in_file = fopen(argv[1], "w");


	if (argc != 2) { // you need the file name
		fprintf(stderr, "You need to give at least one argument\n");
		return 1;
	}
	// attempt to print the stdout (which becomes the input) stream
	while ( fgets(line, 80, stdin) != NULL) {
		puts(line);
		fprintf(in_file, "%s\n", line);
	}
	fclose(in_file);
	return 0;
}