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

void swap(int *pa, int i, int j)
{
    int temp = pa[i];
    pa[i] = pa[j];
    pa[j] = temp;
}

void reverseArray(int *arr, int dl)
{
    for (int i = 0, j = dl - 1; i < dl / 2; i++, j--)
    {
        swap(arr, i, j);
    }
}

void printArray(int *pa, int dl)
{
    for (int i = 0; i < dl; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
}

int main()
{
    int arr[DIM];
    int dl = scanArray(arr);
    printf("Original Array: ");
    printArray(arr, dl);
    reverseArray(arr, dl);
    printf("Reversed Array: ");
    printArray(arr, dl);
    return 0;
}
