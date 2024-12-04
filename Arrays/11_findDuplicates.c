#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

int randNum(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void initArray(int *arr)
{
    for (int i = 0; i < DIM; i++)
    {
        arr[i] = randNum(0, DIM - 1);
    }
}

int *findDuplicates(int *arr)
{
    int *freq = malloc(DIM * sizeof(int));
    // I initialize the frequencies array to 0
    for (int i = 0; i < DIM; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < DIM; i++)
    {
        freq[arr[i]]++;
    }

    return freq;
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
    srand(time(NULL));
    int a[DIM];
    int *b;
    initArray(a);
    printArray(a, DIM);
    b = findDuplicates(a);
    printf("DUPLICATES: ");
    for (int i = 0; i < DIM; i++)
    {
        if (b[i] > 1)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}
