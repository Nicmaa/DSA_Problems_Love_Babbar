#include <stdio.h>
#include <stdlib.h>

void scanArray(int *pa, int dim)
{
    printf("Write your numbers: ");
    for (int i = 0; i < dim; i++)
    {
        if (scanf("%d", &pa[i]) != 1)
        {
            printf("Invalid Input\n");
            exit(1);
        };
    }
}

int maximum(int a, int b) { return a > b ? a : b; }
int minimum(int a, int b) { return a > b ? b : a; }

void maxAndMin(int *pa, int dim, int *max, int *min)
{
    *max = *pa;
    *min = *pa;
    if (dim == 1)
        return;
    else if (dim == 2)
    {
        *max = maximum(pa[0], pa[1]);
        *min = minimum(pa[0], pa[1]);
    }
    else
    {
        int maybeMax, maybeMin;
        for (int i = 1; i < dim; i += 2)
        {
            maybeMax = maximum(pa[i - 1], pa[i]);
            maybeMin = minimum(pa[i - 1], pa[i]);
            *max = maximum(*max, maybeMax);
            *min = minimum(*min, maybeMin);
        }
        if (dim % 2 != 0)
        {
            *max = maximum(*max, pa[dim - 1]);
            *min = minimum(*min, pa[dim - 1]);
        }
    }
}

int main()
{
    int dim, max, min;
    printf("How many elements to add: ");
    if (scanf("%d", &dim) != 1 || dim <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }
    /* DYNAMIC ARRAY
    int *arr = malloc(dim * sizeof(int));
    if (arr == NULL)
    {
        printf("Error in memory allocation");
        exit(1);
    }
    */
    // STATIC ARRAY (VLA)
    int arr[dim];
    scanArray(arr, dim);
    maxAndMin(arr, dim, &max, &min);
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);
    return 0;
}
