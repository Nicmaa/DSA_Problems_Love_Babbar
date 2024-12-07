#include <stdio.h>
#include <stdlib.h>

int *scanArray(int dim)
{
    int *a = malloc(dim * sizeof(int));
    printf("Write your numbers: ");
    for (int i = 0; i < dim; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            printf("Invalid input!\n");
            exit(1);
        }
    }
    return a;
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

int maximum(int a, int b) { return a > b ? a : b; }

int kadaneAlgo(int *arr, int dim)
{
    int max = arr[0], maybeMax = 0;
    for (int i = 0; i < dim; i++)
    {
        maybeMax += arr[i];
        max = maximum(max, maybeMax);
        if (maybeMax < 0)
            maybeMax = 0;
    }
    return max;
}

int main()
{
    int el;
    printf("How many elements? ");
    if (scanf("%d", &el) != 1 || el <= 0)
    {
        printf("Invalid Input!\n");
        exit(2);
    }
    int *arr = scanArray(el);
    printArray(arr, el);
    printf("Max Sum: %d\n", kadaneAlgo(arr, el));
    return 0;
}
