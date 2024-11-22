#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

int randomNumber()
{
    // Creating random number from -200 to 200
    return -200 + rand() % 401; // Using min + rand() % (max-min+1)
}

void createArray(int *pa)
{
    for (int i = 0; i < DIM; i++)
    {
        pa[i] = randomNumber();
    }
}

void printArray(int *pa)
{
    for (int i = 0; i < DIM; i++)
    {
        printf("%d ", pa[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void divideNegative(int *pa)
{
    int low = 0, mid = 0, high = DIM - 1;
    while (mid <= high)
    {
        if (pa[mid] < 0)
        {
            swap(&pa[mid], &pa[low]);
            low++;
            mid++;
        }
        else
        {
            swap(&pa[mid], &pa[high]);
            high--;
        }
    }
}

int main()
{
    int arr[DIM];
    srand(time(NULL));
    createArray(arr);
    printf("Starting Array: ");
    printArray(arr);
    divideNegative(arr);
    printf("Divided Array: ");
    printArray(arr);
    return 0;
}
