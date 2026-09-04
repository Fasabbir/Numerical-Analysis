#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 3 * x - cos(x) - 1;
}

int main()
{
    float a, b, c, error = 0.001;
    int i;

    printf("Enter the Value of a & b = ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) >= 0)
    {
        printf("Invalid Interval. Root Not Generated\n");
        return 0;
    }

    for (i = 1; i <= 50; i++)
    {
        c = (a + b) / 2;

        if (fabs(f(c)) < error)
        {
            break;
        }

        if (f(a) * f(c) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    printf("Approximate Root = %.6f\n", c);
    

    return 0;
}