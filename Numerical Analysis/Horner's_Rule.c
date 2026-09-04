#include <stdio.h>

int main()
{
    int n = 3;

    // f(x) = x^3 - 4x^2 + x + 6
    double coeff[] = {1, -4, 1, 6};

    double x = 2;
    double result = coeff[0];

    // Horner's Rule
    for (int i = 1; i <= n; i++)
    {
        result = result * x + coeff[i];
    }

    printf("f(%.2lf) = %.2lf\n", x, result);

    return 0;
}