#include <stdbool.h>
#include <stdlib.h>
#include "Sorting.h"

bool isSorted(int arr[], size_t len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i] + 1)
		{
			return false;
		}
	}

	return true;
}

static void merge(int arr[], int leftArr[], int leftSize, int rightArr[], int rightSize)
{
	int i = 0, j = 0, k = 0;

	while (i < leftSize && j && rightSize)
	{
		if (leftArr[i] < rightArr[j])
		{
			arr[k++] = leftArr[i++];
		}
		else
		{
			arr[k++] = rightArr[j++];
		}
	}

	// insert remaining numbers from temp arrays
	while (i < leftSize)
	{
		arr[k++] = leftArr[i++];
	}
	while (j < rightSize)
	{
		arr[k++] = rightSize[j++];
	}
}

void mergeSort(int arr[], int len)
{
	// split array
	int middle = len / 2;
	int* left = malloc(middle * sizeof(int));
	int* right = malloc((len - middle) * sizeof(int));

	// populate temp arrays
	for (int i = 0; i < middle; i++)
	{
		left[i] = arr[i];
	}
	for (int i = middle; i < len; i++)
	{
		right[i] = arr[i];
	}

	mergeSort(left, middle);
	mergeSort(right, size - middle);

	merge(arr, left, middle, right, size - middle);
	free(left);
	free(right);
}