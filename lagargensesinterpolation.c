#include <stdio.h>

int main() {
    float x[100], fx[100], xp, fxp = 0, sum1, sum2;
    int n, i, j;
    printf("Enter how many terms: ");
    scanf("%d", &n);
    printf("Enter value of x's: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter value of f(x)'s: ");
    for (i = 0; i < n; i++) {
        scanf("%f", &fx[i]);
    }
    printf("Enter interpolation point: ");
    scanf("%f", &xp);
    for (i = 0; i < n; i++) {
        sum1 = 1;
        sum2 = 1;

        for (j = 0; j < n; j++) {
            if (i != j) {
                sum1 *= (xp - x[j]);
                sum2 *= (x[i] - x[j]);
            }
        }
        fxp += fx[i] * (sum1 / sum2);
    }
    printf("The interpolated value of f(x) at %g is %g", xp, fxp);
}

