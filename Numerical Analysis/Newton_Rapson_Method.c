#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x - cos(x) - 1;
}

float df(float x)
{
    return 3 + sin(x);
}

int main()
{
    float a, b, x0, x1, error = 0.001;
    int i;

    printf("Enter the value of a and b = ");
    scanf("%f %f", &a, &b);

    // Check valid interval
    if (f(a) * f(b) >= 0)
    {
        printf("Invalid Interval. Root Not Generated\n");
        return 0;
    }
 
    // Initial value is the midpoint of a and b
    x0 = (a + b) / 2;

    for (i = 1; i <= 50; i++)
    {
        // Newton-Raphson Formula
        x1 = x0 - (f(x0) / df(x0));

        if (fabs(f(x1)) < error)
        {
            break;
        }

        x0 = x1;
    }

    printf("Approximate Root = %.6f\n", x1);

    return 0;
}