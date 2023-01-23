#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm
 * @array: Array containing integers
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t index = 1;
	int sorted = FALSE, swapped = FALSE, temp_number;

	if (!array || size < 2)
		return;

	while (!sorted)
	{
		if (array[index - 1] > array[index])
		{
			temp_number = array[index - 1];
			array[index - 1] = array[index];
			array[index] = temp_number;
			swapped = TRUE;
			print_array(array, size);
		}

		index++;
		if (index == size && swapped)
			index = 1, swapped = FALSE;
		else if (index == size && !swapped)
			sorted = TRUE;
	}
}
