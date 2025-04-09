#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, max;
	int *count, *sorted;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if ((size_t)array[i] > max)
			max = array[i];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		sorted[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
