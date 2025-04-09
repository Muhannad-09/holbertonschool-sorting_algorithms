#include "sort.h"

/**
 * shell_sort - sort an array in ascending order
 * using the Knuth sequence
 * @array: pointer to first element in array
 * @size: element in array
*/


void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t index, gap, n;

	gap = 1;

	if (!array || size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		/* do a gapped insertion sort for this gap size. */
		/* the first gap elements array[0..gap-1] are already in gapped order */
		/* keep adding one more element until the entire array is gap sorted */
		for (index = gap; index < size; index += 1)
		{
			/* add array[j] to the elements that have been gap sorted */
			/* save array[j] in temp and make a hole at position j */
			tmp = array[index];
			/* shift earlier gap-sorted elements up until the correct */
			/* location for array[j] is found */
			for (n = index; n >= gap && tmp < array[n - gap]; n -= gap)
				array[n] = array[n - gap];
			/* put tmp (the original array[j]) in its correct location */
			array[n] = tmp;
		}
		/* decreasing the interval */
		gap /= 3;
		/*  print the array each time you decrease the interval */
		print_array(array, size);
	}
}
