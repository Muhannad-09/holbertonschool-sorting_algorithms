#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - merges two sorted subarrays
 * @array: original array
 * @left: starting index
 * @mid: middle index
 * @right: ending index
 * @buffer: allocated temporary buffer
 */
void merge(int *array, int left, int mid, int right, int *buffer)
{
	int i = left, j = mid, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] < array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}
	while (i < mid)
		buffer[k++] = array[i++];
	while (j < right)
		buffer[k++] = array[j++];

	for (i = left, k = 0; i < right; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_rec - recursive function for merge sort
 * @array: the array to sort
 * @left: starting index
 * @right: ending index
 * @buffer: pre-allocated buffer
 */
void merge_sort_rec(int *array, int left, int right, int *buffer)
{
	int mid;

	if (right - left > 1)
	{
		mid = (left + right) / 2;
		merge_sort_rec(array, left, mid, buffer);
		merge_sort_rec(array, mid, right, buffer);
		merge(array, left, mid, right, buffer);
	}
}

/**
 * merge_sort - sorts an array using top-down Merge Sort algorithm
 * @array: the array to sort
 * @size: number of elements
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (!array || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;

	merge_sort_rec(array, 0, size, buffer);
	free(buffer);
}
