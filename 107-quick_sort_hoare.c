#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions an array using Hoare partition scheme
 * @array: The array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array for printing
 *
 * Return: The partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - Recursively sorts an array using Hoare partition scheme
 * @array: The array of integers
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 */
void hoare_sort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		hoare_sort(array, low, p, size);
		hoare_sort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using Quick Sort with Hoare partition
 * @array: The array of integers to sort
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, (int)size - 1, size);
}
