#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//remove_duplicates reads from the stream fp and prints its lines that are not consecutive and duplicates
//it will read line 1 and print it
//then for all follwoing lines it read the new line in line2 and strcmp line1 to line2
//if the 2 lines are not the same it will print line2
//then it will swap all the buffers so that our current line will now be compared with the next for the next iteration

void remove_duplicates(FILE *fp) {
	size_t size1 = 0;
	char *line1 = NULL;
	ssize_t chars1 = 0;
	size_t size2 = 0;
	char *line2 = NULL;  
	ssize_t chars2 = 0;
	
	if((chars1 = getline(&line1, &size1, fp)) != -1)
		printf("%s" , line1);

	
	while((chars2 = getline(&line2, &size2, fp)) != -1) {
		if(strcmp(line1, line2) != 0) {  //compare current line (line2) with previous line (line1)
			printf("%s", line2);

			char *line = line1;
			size_t size = size1; 
			line1 = line2; // line1 -> line2 (last printed line)
			size1 = size2; 
			line2 = line; // line2 -> line (the old line1)
			size2 = size;	
		}
		//will overwrite line2 in next loop iteration
	}
	free(line1);
	free(line2);
}


int main(int argc, char *argv[]) {
	FILE *fp;
	
	if(argc == 1)
		fp = stdin;
	else if(argc == 2) {
		fp = fopen(argv[1], "r");
		if(fp == NULL) {
			printf("Could not open file.\n");
			return 1;
		}
	}
	else if(argc > 2) {
		printf("Too many arguments. Please enter file name only.\n");
		return 1;
	}

	remove_duplicates(fp);
	if(argc == 2)
		fclose(fp);
	
	return 0;
}
