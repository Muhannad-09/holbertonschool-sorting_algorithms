#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Hoare partition scheme
 * @array: array to partition
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: index for partitioning
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
 * quicksort_hoare - recursively sorts using Hoare partition
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = hoare_partition(array, low, high, size);
		quicksort_hoare(array, low, p, size);
		quicksort_hoare(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - sorts array using quick sort (hoare)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}
