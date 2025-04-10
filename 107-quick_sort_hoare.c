#include "sort.h"
#include <stdio.h>

void quicksort_fn_hoare(int *array, int low, int high, size_t size);
int hoare_rt_pvt(int *A, int left, int right, size_t size);
void swap(int *x, int *y);

/**
 * quick_sort_hoare - base of quicksort_fn_hoare
 * @array: array of numbers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_fn_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_fn_hoare - quick sort algorithm
 * @A: array of numbers
 * @low: the first index
 * @high: the last index
 * @size: size of the array
 */
void quicksort_fn_hoare(int A[], int low, int high, size_t size)
{
	int partitionIndex;

	if (high > low)
	{
		partitionIndex = hoare_rt_pvt(A, low, high, size);
		quicksort_fn_hoare(A, low, partitionIndex - 1, size);
		quicksort_fn_hoare(A, partitionIndex, high, size);
	}
}

/**
 * hoare_rt_pvt - the hoare partitioning scheme for quick sort
 * @A: array of integers
 * @left: partition start index
 * @right: partition last index
 * @size: size of the array
 * Return: partition index
 */
int hoare_rt_pvt(int A[], int left, int right, size_t size)
{
	int pivot, i, j;

	pivot = A[right];
	i = left - 1;
	j = right + 1;

	while (i < j)
	{
		while (A[++i] < pivot)
			;
		while (A[--j] > pivot)
			;

		if (i < j)
		{
			swap(&A[i], &A[j]);
			print_array(A, size);
		}
	}
	return (i);
}

/**
 * swap - swaps two integer pointers
 * @x: first int variable
 * @y: second int variable
 */
void swap(int *x, int *y)
{
	int tm;

	tm = *x;
	*x = *y;
	*y = tm;
}
