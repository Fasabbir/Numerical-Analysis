#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1/x;
}

int main()
{
    float a, b, h, sum = 0, result;
    int n, i;

    printf("Enter the lower limit (a) = ");
    scanf("%f", &a);

    printf("Enter the upper limit (b) = ");
    scanf("%f", &b);

    printf("Enter the number of intervals (n) = ");
    scanf("%d", &n);

    
    h = (b - a) / n;

    
    sum = f(a) + f(b);

    
    for (i = 1; i < n; i++)
    {
        float x = a + i * h;
        sum = sum + 2 * f(x);
    }

    // Trapezoidal Rule Formula
    result = (h / 2) * sum;

    printf("\nApproximate Integration = %.6f\n", result);

    return 0;
}