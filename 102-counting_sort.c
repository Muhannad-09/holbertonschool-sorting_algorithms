#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * find_max - Finds the maximum number in the array
 * @array: Array to search
 * @size: Size of the array
 * Return: The maximum integer
 */
int find_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * build_count_array - Builds and fills count array
 * @array: Input array
 * @size: Size of input array
 * @max: Max number in array
 * Return: Pointer to count array or NULL on failure
 */
int *build_count_array(int *array, size_t size, int max)
{
	int *count;
	size_t i;

	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return (NULL);

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);
	return (count);
}

/**
 * counting_sort - Sorts an array using Counting sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i;
	int max;

	if (array == NULL || size < 2)
		return;

	max = find_max(array, size);
	count = build_count_array(array, size, max);
	if (!count)
		return;

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
