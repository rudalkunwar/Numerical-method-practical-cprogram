#include <stdio.h>

#define N 100

void gaussElimination(float mat[N][N], float b[N], int n)
{
    int i, j, k;
    
    // Forward elimination
    for (i = 0; i < n - 1; i++) {
        for (k = i + 1; k < n; k++) {
            float factor = mat[k][i] / mat[i][i];
            for (j = i; j < n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    float x[N];
    for (i = n - 1; i >= 0; i--) {
        x[i] = b[i];
        for (j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    // Print the solution
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %g\n", i, x[i]);
    }
}

int main()
{
    int n, i, j;
    float mat[N][N], b[N];

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%f", &mat[i][j]);
        }
        scanf("%f", &b[i]);
    }

    gaussElimination(mat, b, n);

    return 0;
}
