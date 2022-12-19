#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char *ptr[10];
    char temp[30];
    int index,iterator;
    
    for (index = 0; index < 10; index++) {
        printf("Enter name %d:\n", index+1);
	ptr[index] = (char*)malloc(30 * sizeof(char));
        scanf("%s", ptr[index]);
    }
    
    for (index = 0; index < 10; index ++) {

	    for (iterator = index + 1; iterator < 10 ; iterator ++) {
	        if (strcmp(ptr[index], ptr[iterator]) > 0) {
		    strcpy( temp, ptr[index]);
	            strcpy(ptr[index], ptr[iterator]);
	            strcpy (ptr[iterator], temp);
		    }
	    }
    }
    printf("\nsorted names:\n");

    for (index = 0; index < 10 ; index++) {
        printf("%s\n", ptr[index]);
    }
}


