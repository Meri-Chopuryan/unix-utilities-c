#include <stdio.h>

//counts reads the input stream, takes in 3 int ptrs
//chars points to character count
//words points to word count
//lines points to line count
//the function counts total characters, words, and lines

void counts(FILE *fp, int *chars, int *words, int *lines) {
	*chars = 0;
	*words = 0;
	*lines = 0;
	int prev_char = 0;  //assumes previous char was whitespace
	int ch;

	while((ch = fgetc(fp)) != EOF) {
		(*chars)++;

		if(ch == '\n')
			(*lines)++;
	
		int whitespace = (ch == ' ' || ch == '\t' || ch == '\n');
		
		if(!whitespace && prev_char == 0) {
			(*words)++; //current ch is not whitespace and the prev char is so it must be a new word			
		}
	 	if(whitespace)
			prev_char = 0; //current char is whitespace, updated for next iteration of loop
		else
			prev_char = 1;
	}
}


int main(int argc, char *argv[]) {
	FILE *fp;
	
	if(argc == 1) {
		fp = stdin;
	}
	else if(argc == 2) {
		fp = fopen(argv[1] , "r");

		if(fp == NULL){
			printf("Could not open file for reading\n");
			return 1;
		}
	}
	else if(argc > 2) {
		printf("Too many arguments please only enter the filename\n");
		return 1;
	}

	int ch_count, wrd_count, line_count;
	counts(fp, &ch_count, &wrd_count, &line_count);

	printf("%d %d %d\n", line_count, wrd_count, ch_count);

	if(argc == 2)
		fclose(fp);
	return 0;
}


