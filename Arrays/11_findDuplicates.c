#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void findDuplicates(int *arr)
{
    printf("DUPLICATES: ");
    for (int i = 0; i < DIM; i++)
    {
        int index = arr[i] % DIM;
        arr[index] += DIM;
    }

    for (int i = 0; i < DIM; i++)
    {
        if ((arr[i] / DIM) >= 2)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
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
    initArray(a);
    printArray(a, DIM);
    findDuplicates(a);
    return 0;
}
