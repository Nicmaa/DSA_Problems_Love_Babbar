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

int indexMax(int *pa, int dim)
{
    int max = 0;
    for (int i = 1; i < dim; i++)
    {
        if (pa[max] < pa[i])
        {
            max = i;
        }
    }
    return max;
}

int indexMin(int *pa, int dim)
{
    int min = 0;
    for (int i = 1; i < dim; i++)
    {
        if (pa[min] > pa[i])
        {
            min = i;
        }
    }
    return min;
}

int main()
{
    int dim;
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
    printf("Max: %d\n", arr[indexMax(arr, dim)]);
    printf("Min: %d\n", arr[indexMin(arr, dim)]);
    return 0;
}
