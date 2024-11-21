#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int randomIndex(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int indexResearch(int *pa, int start, int end, int k)
{
    if (start == end)
        return start;
    int pivotIndex = randomIndex(start, end);
    swap(&pa[pivotIndex], &pa[end]);
    int paritionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (pa[i] < pa[end])
        {
            swap(&pa[i], &pa[paritionIndex]);
            paritionIndex++;
        }
    }
    swap(&pa[end], &pa[paritionIndex]);
    if (k == paritionIndex)
        return paritionIndex;
    else if (k < paritionIndex)
        return indexResearch(pa, start, paritionIndex - 1, k);
    else
        return indexResearch(pa, paritionIndex + 1, end, k);
}

int main()
{
    int arr[DIM], k;
    srand(time(NULL));
    int length = scanArray(arr);
    if (length == 0)
    {
        printf("Empty array!\n");
        exit(1);
    }
    printf("K: ");
    if (scanf("%d", &k) != 1 || k > length || k <= 0)
    {
        printf("Error: Invalid value for k\n");
        exit(1);
    };
    printf("K'th element: %d\n", arr[indexResearch(arr, 0, length - 1, k - 1)]);
    return 0;
}
