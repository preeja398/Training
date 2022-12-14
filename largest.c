#include<stdio.h>
#include<stdlib.h>

int main() {
    int *num, index, N, MAX = 0;
    printf("Enter the no of Elements :  ");
    scanf("%d", &N);
    num = (int *) malloc (N * sizeof(int));

    if(num == NULL) {
	    printf("members not allocated");
    } else {

       for(index = 0; index < N; index ++) {
	    printf("Element %d : ", index + 1);
	    scanf("%d",&num[index]);
       }
    }
     
    for(index = 0; index < N; index ++) {
	   
	    if( MAX < num[index]) {
		    MAX = num[index];
	    }
    
    }

    printf("MAX : %d\n",MAX);
    free(num);

}

