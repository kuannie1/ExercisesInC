/* 
word_count.c, 

Takes in a txt file in the command line and saves the frequency of words into a GLib hashtable

I couldn't finish this without segfaulting and implement a whole histogram, so I'm just going to turn in what I have.

Anne Ku
*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>



int main(int argc, char** argv)
{	
	char *fname = argv[1];
	FILE *file = fopen(fname, "r");
	//Make a new hash table
	GHashTable * hash = g_hash_table_new(g_str_hash, g_str_equal);
	char word[256];
	gint one = 1;
	//Looping through each word until we get an EOF
	if (file) {
	    while (fscanf(file, "%s", word)!= EOF){
	    	gchar *key = g_ascii_strdown(word, strlen(word));

	    		if (g_hash_table_contains(hash, key)){
	    			printf("hi");
	    			gint count = (*(gint *) g_hash_table_lookup(hash, key));
	    			g_hash_table_replace(hash, key, count + 1);
	    		} else {
	    			g_hash_table_insert(hash, key, (gpointer) 1);
	    		}
	    }
	    fclose(file);
	}

	printf("%d\n", g_hash_table_size(hash));
	g_hash_table_destroy(hash);
	// 	//Calculates the frequency of words
	// }
	return 0;
}
