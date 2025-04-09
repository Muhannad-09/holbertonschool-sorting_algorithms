#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - Finds the maximum value in an array.
 * @array: The array to scan.
 * @size: Size of the array.
 *
 * Return: Maximum integer in the array.
 */
int get_max(int *array, size_t size)
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
 * fill_count_array - Counts occurrences of each number.
 * @array: The input array.
 * @size: Size of the array.
 * @count: The count array.
 */
void fill_count_array(int *array, size_t size, int *count)
{
	size_t i;

	for (i = 0; i < size; i++)
		count[array[i]]++;
}

/**
 * accumulate_count_array - Turns count array into cumulative sum.
 * @count: The count array.
 * @max: Maximum number in original array.
 */
void accumulate_count_array(int *count, int max)
{
	int i;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
}

/**
 * build_sorted_array - Reconstructs sorted array from counts.
 * @array: Original array.
 * @size: Size of the array.
 * @count: Count array.
 * @output: Output array.
 */
void build_sorted_array(int *array, size_t size, int *count, int *output)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
}

/**
 * counting_sort - Sorts an array using counting sort algorithm.
 * @array: The array to sort.
 * @size: Size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, *count, *output;
	size_t i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	count = calloc(max + 1, sizeof(int));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
		return;

	fill_count_array(array, size, count);
	accumulate_count_array(count, max);
	build_sorted_array(array, size, count, output);

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
