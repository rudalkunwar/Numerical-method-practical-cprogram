#include <stdio.h>

#define N 100

void luFactorization(float mat[N][N], float L[N][N], float U[N][N], int n)
{
    int i, j, k;

    // Initializing L and U matrices
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)
                L[i][j] = 1;
            else
                L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // LU Factorization
    for (i = 0; i < n; i++) {
        // Upper Triangular Matrix
        for (j = i; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = mat[i][j] - sum;
        }

        // Lower Triangular Matrix
        for (j = i + 1; j < n; j++) {
            float sum = 0;
            for (k = 0; k < i; k++) {
                sum += L[j][k] * U[k][i];
            }
            L[j][i] = (mat[j][i] - sum) / U[i][i];
        }
    }

    // Print L matrix
    printf("L matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%g\t", L[i][j]);
        }
        printf("\n");
    }

    // Print U matrix
    printf("U matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%g\t", U[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    float mat[N][N], L[N][N], U[N][N];

    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    printf("Enter the matrix elements:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    luFactorization(mat, L, U, n);

    return 0;
}
