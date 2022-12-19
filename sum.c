#include<stdio.h>
#include<stdlib.h>

int main() {
    int number;
    int *ptr;
    int index;
    int sum = 0;
    printf("Enter the number of elements:\n");
    scanf("%d", &number);
    ptr = (int *)malloc(number * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated\n");
    } else {
	    
          for (index = 0; index < number; index ++) {
	     printf("Enter the %d element:\n", index + 1);
	     scanf("%d", &ptr[index]);
 	     sum += ptr[index];
	  } 
	  printf("Sum of Elements:%d\n", sum);
	  free(ptr);
    } 
}

