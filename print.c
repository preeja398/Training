#include<stdio.h>
#include<stdlib.h>

int main() {
    int lines;
    int words;   
    int characters;
    char ch;    
    FILE *fp = NULL;
    fp = fopen("example.txt", "r");

    if (fp == NULL) {
	     printf("could not open file");
    } else {
        while ((ch = fgetc(fp)) != EOF) {
	    characters++;

        if (ch == ' ' || ch == '\n')  {
	    words++;
	} 

	if (ch == '\n') { 
	    lines++;   
	}
    }	
 }
   
    printf("Lines: %d\n", lines);

    printf("Words: %d\n", words);

    printf("Characters: %d\n", characters);

    fclose(fp);

    return 0; 
}


