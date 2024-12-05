#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
#define MAX 20

int randNum(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void initArray(int *arr)
{
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = randNum(1, MAX);
    }
    qsort(arr, DIM, sizeof(int), compare);
}

void mergeArray(int *a, int *b)
{
    int i = DIM - 1, j = DIM - 1, k = 2 * DIM - 1;

    while (j >= 0)
    {
        if (i >= 0 && a[i] > b[j])
        {
            a[k--] = a[i--];
        }
        else
        {
            a[k--] = b[j--];
        }
    }
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
    int a[2 * DIM], b[DIM];
    srand(time(NULL));
    initArray(a);
    initArray(b);
    printf("A: ");
    printArray(a, DIM);
    printf("B: ");
    printArray(b, DIM);
    mergeArray(a, b);
    printf("Merged Array: ");
    printArray(a, 2 * DIM);
    return 0;
}
