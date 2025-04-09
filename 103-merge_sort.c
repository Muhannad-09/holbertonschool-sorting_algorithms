#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge_subarrays - Merges two subarrays
 * @array: The original array
 * @left: Pointer to left subarray
 * @right: Pointer to right subarray
 * @l_size: Size of the left subarray
 * @r_size: Size of the right subarray
 */
void merge_subarrays(int *array, int *left, int *right, size_t l_size, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, l_size);
	printf("[right]: ");
	print_array(right, r_size);

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < l_size)
		array[k++] = left[i++];
	while (j < r_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, l_size + r_size);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: Array to sort
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (!array || size < 2)
		return;

	mid = size / 2;
	left = malloc(mid * sizeof(int));
	right = malloc((size - mid) * sizeof(int));

	if (!left || !right)
		return;

	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];

	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge_subarrays(array, left, right, mid, size - mid);

	free(left);
	free(right);
}
