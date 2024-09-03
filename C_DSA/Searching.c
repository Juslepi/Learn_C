#include "Searching.h"

int binarySearch_i(int arr[], int target, int len)
{
	int start = 0, end = len - 1;
	while (start <= end)
	{
		int middle = start + (end - start) / 2;
		if (arr[middle] == target)
		{
			return middle;
		}
		else if (target < arr[middle])
		{
			end = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}

	return -1;
}