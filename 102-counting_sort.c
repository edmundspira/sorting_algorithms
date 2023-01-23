#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Implement counting sort algorithm
 * @array: An array of integers
 * @size: The length of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, max_value = 0;
	int *count = NULL, *sorted_array = NULL;

	if (!array || size < 2)
		return;

	max_value = find_max(array, size);

	count = malloc(sizeof(int) * (max_value + 1));
	if (!count)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
	{
		free(count);
		return;
	}

	for (i = 0; i < max_value + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		j = array[i];
		count[j] = count[j] + 1;
	}

	for (i = 1; i <= max_value; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, max_value + 1);

	sort(array, count, sorted_array, size);

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count), free(sorted_array);
}

/**
 * find_max - Find the maximum integer in an array
 * @array: Array of integers
 * @size: Size of the array
 *
 * Return: The maximum integer in the array
 */
int find_max(int *array, size_t size)
{
	int max = 0;
	size_t i;

	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * sort - Sort the integers in the array
 * @array: Array of integers
 * @count: Array of counters
 * @sorted_array: Array of integers in sorted order
 * @size: Size of the array
 */
void sort(int *array, int *count, int *sorted_array, size_t size)
{
	size_t i, j;

	for (i = size - 1; i > 0; i--)
	{
		j = array[i];
		count[j] = count[j] - 1;
		sorted_array[count[j]] = array[i];
	}

	j = array[i];
	count[j] = count[j] - 1;
	sorted_array[count[j]] = array[i];
}
