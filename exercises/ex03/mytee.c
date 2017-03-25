/* 

the tee command, by Anne Ku

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
	char line[80];  //The input line
	// attempt to save contents of stdout into a file
	FILE *in_file = fopen(argv[1], "w");

	// Because the 1st element is "./mytee",
	// we need to make sure this input is of length 2
	if (argc != 2) { 
		fprintf(stderr, "You need to give at least one argument\n"); //print the stderr stream
		return 1;
	}
	
	// If these conditions are satisfied, print the stdout output 
	// and fprintf it to the file specified in the command input
	while ( fgets(line, 80, stdin) != NULL) {
		puts(line);
		fprintf(in_file, "%s\n", line);
	}
	fclose(in_file);
	return 0;
}

//reflection
//This exercise was hard because I spent most of my time trying to
//pull code verbatim from the Head First C examples. I focused too much
//on trying to read stdout but it turns out we just need fgets to read
//in stdout input. 

//After reading up on fgets(), the rest was easy. I just had to print
//the output and use fprintf() to save the output into the command line
//file, similar to the examples in Head First C

// I saw that there was a lot of things I don't have, when comparing this
// solution to the atual source code in coreutils. First of all, it includes
// error handling. The source code contains numerous messages and accounts for
// many more cases. My code, on the other hand, does not handle errors in any 
// way. 

// I tested my program multiple times (so I know it works) but I have trouble finding similarities
// between my code and the source code itself. i'm eying the methods such as 
// xset_binary_mode and buffer, which I don't understand. If I could look into
// how each of those elements worked, I may understand why tee was able to work
// in the terminal. 
