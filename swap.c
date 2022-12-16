#include<stdio.h>

void callByValue(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void callByReference(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    printf("Enter the element of a and b:\n");
    scanf("%d%d", &a, &b);
    printf("Before swap elements:a = %d b = %d\n", a, b);
    callByValue(a, b);
    printf("After swap by call by value a = %d b = %d\n", a, b);
    callByReference(&a, &b);
    printf("After swap by call by reference a = %d b = %d\n", a, b);
}

