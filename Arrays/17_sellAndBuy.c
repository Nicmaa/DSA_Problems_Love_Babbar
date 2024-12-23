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

int minimum(int *arr, int dim)
{
    int m = arr[0];
    for (int i = 1; i < dim; i++)
    {
        if (m > arr[i])
            m = arr[i];
    }
    return m;
}

int best(int *arr, int dim)
{
    int min = arr[0], profit = 0, price;
    for (int i = 1; i < dim; i++)
    {
        min = minimum(arr, i + 1);
        price = arr[i];
        profit = price - min > profit ? price - min : profit;
    }
    return profit;
}

int main()
{
    int arr[DIM];
    int dl = scanArray(arr);
    printf("%d\n", best(arr, dl));
    return 0;
}
