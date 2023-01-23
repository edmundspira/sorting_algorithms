#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 * @array: Array of integers
 * @size: Size of the given array
 */
void selection_sort(int *array, size_t size)
{
	size_t current_idx = 0, unsorted_min_idx, sorted_max_idx = 0;
	int temp = 0;

	if (size < 2 || !array)
		return;

	while (sorted_max_idx < size - 1)
	{
		unsorted_min_idx = sorted_max_idx + 1;
		current_idx = unsorted_min_idx;
		while (current_idx < size)
		{
			if (array[current_idx] < array[unsorted_min_idx])
				unsorted_min_idx = current_idx;
			current_idx++;
		}
		if (array[unsorted_min_idx] < array[sorted_max_idx])
		{
			temp = array[unsorted_min_idx];
			array[unsorted_min_idx] = array[sorted_max_idx];
			array[sorted_max_idx] = temp;
			print_array(array, size);
		}
		sorted_max_idx++;
	}
}
