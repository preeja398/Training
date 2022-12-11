#include<stdio.h>
#include<stdlib.h>

int main() {
    int *num, index, N, MAX;
    printf("Enter the no of Elements :  ");
    scanf("%d", &N);
    num = (int *) malloc (N * sizeof(int));

    for(index = 0; index < N; index ++) {
            printf("Element %d : ", index + 1);
            scanf("%d",&num[index]);
    }

    MAX = num[0];

    for(index = 1; index < N; index ++){
            if( MAX < num[index]) {
                    MAX = num[index];
            }

    }

    printf("MAX : %d\n",MAX);

}

