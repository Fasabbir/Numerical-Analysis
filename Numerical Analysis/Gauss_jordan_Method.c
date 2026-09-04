#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, k;
    float a[10][11], ratio;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix coefficients:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    // Gauss-Jordan Elimination
    for (i = 0; i < n; i++)
    {
        // Check if pivot is zero
        if (a[i][i] == 0)
        {
            printf("Mathematical Error!\n");
            return 0;
        }

        // Make pivot equal to 1
        float pivot = a[i][i];

        for (j = 0; j <= n; j++)
        {
            a[i][j] = a[i][j] / pivot;
        }

        // Make other elements of pivot column zero
        for (k = 0; k < n; k++)
        {
            if (k != i)
            {
                ratio = a[k][i];

                for (j = 0; j <= n; j++)
                {
                    a[k][j] = a[k][j] - ratio * a[i][j];
                }
            }
        }
    }

    printf("\nSolution:\n");

    for (i = 0; i < n; i++)
    {
        printf("x%d = %.6f\n", i + 1, a[i][n]);
    }

    return 0;
}