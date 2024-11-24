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

void rotateArr(int *pa, int dim)
{
    if (dim <= 1)
        return;
    int last = pa[dim - 1];
    for (int i = dim - 1; i > 0; i--)
    {
        pa[i] = pa[i - 1];
    }
    pa[0] = last;
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
    int arr[DIM];
    int dla = scanArray(arr);
    printf("Initial Array: ");
    printArray(arr, dla);
    printf("Array rotated by one: ");
    rotateArr(arr, dla);
    printArray(arr, dla);
    return 0;
}
