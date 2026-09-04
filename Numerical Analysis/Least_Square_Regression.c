#include <stdio.h>

int main()
{
    int n, i;
    float x[100], y[100];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float a, b;

    printf("Enter the number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");

    for (i = 0; i < n; i++)
    {
        printf("x[%d] y[%d] = ", i + 1, i + 1);
        scanf("%f %f", &x[i], &y[i]);

        sumX = sumX + x[i];
        sumY = sumY + y[i];
        sumXY = sumXY + x[i] * y[i];
        sumX2 = sumX2 + x[i] * x[i];
    }

    // Calculate slope (b)
    b = (n * sumXY - sumX * sumY) /
        (n * sumX2 - sumX * sumX);

    // Calculate intercept (a)
    a = (sumY - b * sumX) / n;

    printf("\nRegression Equation:\n");
    printf("y = %.6f + %.6fx\n", a, b);

    return 0;
}