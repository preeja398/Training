#include <stdio.h>

int main() {
    int num, index, factorial=1;
    int *ptr;
    printf("Enter a number: ");
    scanf("%d", &num);
    ptr = &num;
    for (index = 1; index <= *ptr; index ++) {
    factorial = factorial * index;
    }
    printf("Factorial of %d = %d", *ptr, factorial);
    return 0;
}

