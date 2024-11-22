#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

int randomNumber()
{
	return rand() % 3;
}

void createArray(int *pa)
{
	int length = 0;
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

void sortAlgo(int *pa)
{
	int low = 0, mid = 0, high = DIM - 1;
	while (mid <= high)
	{
		switch (pa[mid])
		{
		case 0:
			swap(&pa[mid], &pa[low]);
			low++;
			mid++;
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(&pa[mid], &pa[high]);
			high--;
			break;
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
	sortAlgo(arr);
	printf("Sorted Array: ");
	printArray(arr);
	return 0;
}
