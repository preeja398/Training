#include<stdio.h>

int main() {
    int mat1[10][10][10], mat2[10][10][10], sum_mat[10][10][10];
    int l, n, m;
    int i, j, k;
    printf("Enter the Matrix size : ");
    scanf("%d%d%d", &l, &n, &m);

    printf("Enter the Matrix-1 value \n");
        for (i = 0; i < l; ++i) {
                for ( j = 0; j < n; ++j) {
                        for (k = 0; k < m; ++k) {
                                printf("Matrix Elements --> Mat[%d][%d][%d] : ", i, j, k);
                                scanf("%d",&mat1[i][j][k]);
                        }
                }
        }
	printf("Enter the Matrix-2 value \n");
        for (i = 0; i < l; ++i) {
                for ( j = 0; j < n; ++j) {
                        for (k = 0; k < m; ++k) {
                                printf("Matrix Elements --> Mat[%d][%d][%d] : ", i, j, k);
                                scanf("%d",&mat2[i][j][k]);
                        }
                }
        }
	printf("Sum of Matrix : \n");
        for (i = 0; i < l; ++i) {
                for ( j = 0; j < n; ++j) {
                        for (k = 0; k < m; ++k) {
                                printf("%d ", mat1[i][j][k] + mat2[i][j][k]);
                        }
			printf("\n");
                }
		printf("\n");
        }

        return 0;
}


