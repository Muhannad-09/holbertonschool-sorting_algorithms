#include "sort.h"
#include <stdio.h>

/**
 * swap - swaps two integers
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Lomuto partition scheme for quicksort
 * @array: array of ints
 * @low: starting index
 * @high: ending index
 * @size: size of array (for printing)
 * Return: partition index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
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
 * hoare_sort - recursive quicksort using Hoare partition
 * @array: array of ints
 * @low: starting index
 * @high: ending index
 * @size: array size
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
 * quick_sort_hoare - quicksort with Hoare partition scheme
 * @array: array of ints
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, 0, (int)size - 1, size);
}
