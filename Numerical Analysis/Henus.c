#include <stdio.h>

float f(float x, float y)
{
    return x + y;   // dy/dx = x + y
}

int main()
{
    float x0, y0, h, xn;
    float x, y, yp;
    int n, i;

    printf("Enter initial value of x (x0) = ");
    scanf("%f", &x0);

    printf("Enter initial value of y (y0) = ");
    scanf("%f", &y0);

    printf("Enter step size (h) = ");
    scanf("%f", &h);

    printf("Enter final value of x (xn) = ");
    scanf("%f", &xn);

    x = x0;
    y = y0;

    n = (xn - x0) / h;

    for (i = 1; i <= n; i++)
    {
        // Predictor
        yp = y + h * f(x, y);

        // Corrector
        y = y + (h / 2) *
            (f(x, y) + f(x + h, yp));

        x = x + h;

        printf("x = %.4f, y = %.6f\n", x, y);
    }

    printf("\nApproximate Value = %.6f\n", y);

    return 0;
}