#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[]) {
    FILE *fp = NULL;
    char buffer[20];
    char ch;
    int count = 0;
    int index = 0;
    int iterator;
    
    if (argc != 3) {
        printf("Invalid argument\n");
	printf("Enter in following format\n");
	printf("./a.out pattern filename\n");
    } else {
          fp = fopen(argv[2], "r");
	  
	  if (fp == NULL) {
              printf("Unable to open %s\n", argv[2]);
	  } else {
                while(1) {
	            ch = fgetc(fp);
		    
		    if (ch == EOF) {
	                break;
		    } else if (ch == ' ' || ch == '\n') {
		          if (strcmp (buffer, argv[1]) == 0) {
		              count ++ ;
			  }

			  for(iterator = 0; iterator < 20; iterator++  ) {
			      buffer[iterator] = '\0';
			  } index = 0; 
		    }
		    else {
		        buffer[index] = ch;
			index++;
		    }
		}
		printf("No.of time %s in %s = %d\n", argv[1],argv[2], count);
		fclose(fp);
	  }
    }
}
