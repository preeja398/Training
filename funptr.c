#include<stdio.h>

void primeFactor(int);

void primeFactor(int number) {
    int index;

    for (index = 2; index <= number; index ++) {
	while (number % index == 0) {
	    printf("%d\n", index);
    	    number /= index;
	}
    }
}

int main () {
    int integer;	
    void (*ptr)(int);
    ptr =  &primeFactor;
    printf("Enter the integer:\n");
    scanf("%d", &integer);
    (*ptr)(integer);
}    

