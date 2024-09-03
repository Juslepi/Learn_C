#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <stdbool.h>;
#include "Searching.h"
#include "Sorting.h"
#include "Helpers.h"

int main()
{
	int arr[4] = { 1, 2, 4, 8 };
	int arr2[6] = { 5, 25, 125, 625, 1225, 2225 };
	int arr3[6] = { 7, 1, 7, 49, 22, 6 };

	//int index = binarySearch_i(arr2, 2225, 6);
	//printf("%i", index);

	int len = sizeof(arr3) / sizeof(int);
	printf("Array: ");
	printArray(arr3, len);
	mergeSort(arr3, len);
	printf("After sorting: ");
	printArray(arr3, len);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
