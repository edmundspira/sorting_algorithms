#include "sort.h"

/**
 * shell_sort - Sorts an array of ints in ascending order with shell sort algo
 * @array: Array of integers
 * @size: Size of the array
 *
 * Description: It uses the Knuth's sequence to find the intervals
 */
void shell_sort(int *array, size_t size)
{
	shell_sort_struct sort = {NULL, 0, 0, 0, 0, 0, 0, 0};
	shell_sort_struct *utils = &sort;

	if (size < 2 || !array)
		return;

	utils->array = array;
	utils->interval = 1;
	utils->size = size;

	while (utils->interval < utils->size / 3)
		utils->interval = utils->interval * 3 + 1;

	while (utils->interval >= 1)
	{
		compare_and_swap(utils);
		print_array(utils->array, utils->size);
		utils->interval /= 3;
	}

	if (is_sorted(utils))
		return;

	do_insertion_sort(utils);
}

/**
 * compare_and_swap - Compares integers at the intervals and swaps if needed
 * @utils: Pointer to a structure of utility values
 */
void compare_and_swap(shell_sort_struct *utils)
{
	int swap;

	utils->curr_idx = utils->interval;

	while (utils->curr_idx < utils->size)
	{
		utils->high_idx = utils->curr_idx;

		while (utils->high_idx >= utils->interval &&
			utils->array[utils->high_idx] <
			utils->array[utils->high_idx - utils->interval])
		{
			swap = utils->array[utils->high_idx];
			utils->array[utils->high_idx] = utils->array[
				utils->high_idx - utils->interval];
			utils->array[utils->high_idx - utils->interval] = swap;
			utils->high_idx -= utils->interval;
		}
		utils->curr_idx++;
	}
}

/**
 * is_sorted - Check the array is sorted after Knuth's sequence is finished
 * @utils: Strucuture with utility values
 *
 * Return: TRUE if the array is sorted, FALSE otherwise
 */
int is_sorted(shell_sort_struct *utils)
{
	utils->i = 0;

	while (utils->i < utils->size - 1)
	{
		if (utils->array[utils->i] < utils->array[utils->i + 1])
		{
			utils->i++;
			continue;
		}

		break;
	}

	if (utils->i == utils->size - 1)
		return (TRUE);

	return (FALSE);
}

/**
 * do_insertion_sort - Performs insertion sort on a given array of integers
 * @utils: Strucuture with utility values
 */
void do_insertion_sort(shell_sort_struct *utils)
{
	utils->insert = 1;

	while (utils->insert < utils->size)
	{
		utils->idx = 0;
		while (utils->idx < utils->insert)
		{
			check_and_swap(utils);
			utils->idx++;
		}
		utils->insert++;
	}
}

/**
 * check_and_swap - if two values during insertion sort need swapping it swaps
 * @utils: Strucuture with utility values
 */
void check_and_swap(shell_sort_struct *utils)
{
	int swap;

	if (utils->array[utils->insert] < utils->array[utils->idx])
	{
		swap = utils->array[utils->insert];
		utils->array[utils->insert] = utils->array[utils->idx];
		utils->array[utils->idx] = swap;
		print_array(utils->array, utils->size);
	}
}
