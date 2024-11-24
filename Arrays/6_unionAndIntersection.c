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

int isIn(int *arr, int dim, int num)
{
    for (int i = 0; i < dim; i++)
    {
        if (arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}

int *unioneArray(int *pa, int *pb, int dla, int dlb, int *dres)
{
    int *arr = malloc((dla + dlb) * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < dla; i++)
    {
        if (!(isIn(arr, *dres, pa[i])))
        {
            arr[(*dres)++] = pa[i];
        }
    }
    for (int i = 0; i < dlb; i++)
    {
        if (!(isIn(arr, *dres, pb[i])))
        {
            arr[(*dres)++] = pb[i];
        }
    }
    return arr;
}

int *intersectionArray(int *pa, int *pb, int dla, int dlb, int *dres)
{
    int *arr = malloc(dla * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    for (int i = 0; i < dla; i++)
    {
        if (isIn(pb, dlb, pa[i]) && !isIn(arr, *dres, pa[i]))
        {
            arr[(*dres)++] = pa[i];
        }
    }
    return arr;
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
    int a[DIM], b[DIM], dunion = 0, dintersection = 0;
    int dla = scanArray(a);
    int dlb = scanArray(b);
    printf("First Array: ");
    printArray(a, dla);
    printf("Second Array: ");
    printArray(b, dlb);
    int *arr = unioneArray(a, b, dla, dlb, &dunion);
    printf("Union Array: ");
    printArray(arr, dunion);
    free(arr);
    int *array = intersectionArray(a, b, dla, dlb, &dintersection);
    printf("Intersection Array: ");
    printArray(array, dintersection);
    free(array);
    return 0;
}
