#include<stdio.h>

int bin(int);
int main() {
    int N, binary;
    printf("Enter the No : ");
    scanf("%d", &N);
    binary = bin(N);
    printf("%d\n", binary);
    return 0;
}

int bin(int n) {
    if (n == 0) {
    return 0;
    }
    else {
      return ( n%2 + 10 * bin(n/2) );
    }
  
}

