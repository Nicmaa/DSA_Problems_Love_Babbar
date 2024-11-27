#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int minJump(int *arr, int dim)
{
    if (arr == NULL || dim == 0)
        return -1;
    int index = 0, jump = 0;
    if (dim == 1)
        return jump;
    for (int i = index; i < dim; i = index)
    {
        if (index + arr[index] >= dim - 1)
        {
            jump++;
            return jump;
        }
        int maxReach = 0;
        for (int j = i + 1; j <= i + arr[i] && j < dim; j++)
        {
            if (j + arr[j] >= dim - 1)
                return jump + 2;
            else
            {
                if (maxReach < j + arr[j])
                {
                    maxReach = j + arr[j];
                    index = j;
                }
            }
        }
        if (maxReach == 0)
        {
            jump = -1;
            return jump;
        }
        jump++;
    }
    return jump;
}

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

int main()
{
    int a[DIM];
    int dim = scanArray(a);
    int numJump = minJump(a, dim);
    if (numJump == -1)
        printf("Impossible to exit!\n");
    else
        printf("Min Jump: %d\n", numJump);
    return 0;
}
