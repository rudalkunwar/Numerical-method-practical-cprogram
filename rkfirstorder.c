#include <stdio.h>

float f(float x, float y)
{
    // Define the differential equation dy/dx
    // Example: dy/dx = x + y
    return x + y;
}

void rungeKutta(float x0, float y0, float h, float xn)
{
    int steps = (int)((xn - x0) / h);

    float x = x0, y = y0;

    for (int i = 0; i < steps; i++) {
        float k1 = h * f(x, y);
        float k2 = h * f(x + h / 2, y + k1 / 2);
        float k3 = h * f(x + h / 2, y + k2 / 2);
        float k4 = h * f(x + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x = x + h;
    }

    printf("The value of y at x = %g is %g", xn, y);
}

int main()
{
    float x0, y0, h, xn;

    printf("Enter initial value of x: ");
    scanf("%f", &x0);
    printf("Enter initial value of y: ");
    scanf("%f", &y0);
    printf("Enter step size h: ");
    scanf("%f", &h);
    printf("Enter the value of x at which y is required: ");
    scanf("%f", &xn);

    rungeKutta(x0, y0, h, xn);

    return 0;
}
