#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int scanArray(int *pa)
{
    int length = 0;
    printf("Write your numbers (-1 to stop): ");
    while (length < DIM)
    {
        if (scanf("%d", &pa[length]) != 1)
        {
            printf("Invalid Input\n");
            exit(1);
        };
        if (pa[length] == -1)
            break;
        length++;
    }
    return length;
}

int maximum(int a, int b) { return a > b ? a : b; }

int maxSum(int *pa, int dim)
{
    int max = pa[0], maybeMax = 0;
    for (int i = 0; i < dim; i++)
    {
        maybeMax += pa[i];
        max = maximum(max, maybeMax);
        if (maybeMax < 0)
            maybeMax = 0;
    }
    return max;
}

void printArray(int *pa, int dim)
{
    if (dim == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < dim; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
}

int main()
{
    int a[DIM];
    int dim = scanArray(a);
    printf("Initial Array: ");
    printArray(a, dim);
    printf("Maximum Sum: %d\n", maxSum(a, dim));
    return 0;
}
