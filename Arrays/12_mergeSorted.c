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

int *mergeArray(int *a, int *b)
{
    int *c = (int *)malloc(2 * DIM * sizeof(int));
    if (!c)
    {
        printf("Failed to allocate memory!\n");
        exit(1);
    }

    int i = 0, j = 0, z = 0;

    while (i < DIM && j < DIM)
    {
        if (a[i] > b[j])
            c[z++] = b[j++];
        else
            c[z++] = a[i++];
    }
    while (i < DIM)
        c[z++] = a[i++];
    while (j < DIM)
        c[z++] = b[j++];

    return c;
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
    int a[DIM], b[DIM];
    srand(time(NULL));
    initArray(a);
    initArray(b);
    printf("A: ");
    printArray(a, DIM);
    printf("B: ");
    printArray(b, DIM);
    int *c = mergeArray(a, b);
    printf("Merged Array: ");
    printArray(c, 2 * DIM);
    free(c);
    return 0;
}
