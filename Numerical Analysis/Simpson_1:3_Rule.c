#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1 / x;
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

    // Simpson's 1/3 Rule requires even n
    if (n % 2 != 0)
    {
        printf("Number of intervals must be even!\n");
        return 0;
    }

    
    h = (b - a) / n;
   
    sum = f(a) + f(b);

    for (i = 1; i < n; i++)
    {

        if (i % 2 == 0)
        {
            sum = sum + 2 * f(a+i*h);
        }
        else
        {
            sum = sum + 4 * f(a+i*h);
        }
    }

    // Simpson's 1/3 Rule Formula
    result = (h / 3) * sum;

    printf("\nApproximate Integration = %.6f\n", result);

    return 0;
}