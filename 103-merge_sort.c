i#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Implements the merge sort algorithm using an array of ints
 * @array: Array of ints
 * @size: Length of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array = NULL;

	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);
	if (!temp_array)
		return;

	copy_array(array, temp_array, size);
	split(temp_array, 0, size, array);
	free(temp_array);
}

/**
 * copy_array - Copies the integers in @array of size @size to @temp_array
 * @array: Source array
 * @temp_array: Destination array
 * @size: Length of @array
 */
void copy_array(int *array, int *temp_array, size_t size)
{
	size_t idx;

	for (idx = 0; idx < size; idx++)
		temp_array[idx] = array[idx];
}

/**
 * split - Divides an array into two until each array has one integer only
 * @temp_array: Temporary array for working on the sort
 * @beg: Beginning index in the array
 * @end: Ending index in the array
 * @array: Main array
 */
void split(int *temp_array, size_t beg, size_t end, int *array)
{
	size_t mid = 0;

	if (end - beg < 2)
		return;

	mid = (end + beg) / 2;

	split(array, beg, mid, temp_array);
	split(array, mid, end, temp_array);

	merge(temp_array, beg, mid, end, array);
}

/**
 * merge - Merges integers in two array in a sorted order
 * @array: Second array
 * @beg: Start index in the array
 * @mid: Middle index in the array
 * @end: End index in the array
 * @temp_array: First array
 */
void merge(int *array, size_t beg, size_t mid, size_t end, int *temp_array)
{
	size_t i = beg, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + beg, mid - beg);
	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (k = beg; k < end; k++)
	{
		if (i < mid && (j >= end || array[i] <= array[j]))
			temp_array[k] = array[i], i++;
		else
			temp_array[k] = array[j], j++;
	}

	printf("[Done]: ");
	print_array(temp_array + beg, end - beg);
}
