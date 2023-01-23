#include "sort.h"

/**
 * quick_sort - Implementation of quick sort algorithm using an array of ints
 * @array: Array of ints
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;

	quick_sort_lomuto(array, size, 0, size - 1);
}

/**
 * quick_sort_lomuto - Sorts an array of ints in ascending order
 * @array: Array of ints
 * @size: Size of the array
 * @left: Index of left-most int in the sub-array
 * @right: Index of the right-most int in the sub-array
 *
 * Description: The function uses quick sort algorithm, with the Lomuto
 * Partition Scheme.
 */
void quick_sort_lomuto(int *array, size_t size, ssize_t left, ssize_t right)
{
	int swap;
	quick_sort_struct sort = {NULL, 0, 0, 0, 0, 0, 0};
	quick_sort_struct *utils = &sort;

	utils->array = array;
	utils->curr_int_idx = left;
	utils->left = left;
	utils->right = right;
	utils->pivot_idx = left - 1;
	utils->size = size;
	utils->pivot = array[right];

	if (utils->left < utils->right)
	{
		find_and_move_lesser_numbers(utils);

		if (utils->pivot_idx + 1 != utils->right)
		{
			swap = utils->array[utils->pivot_idx + 1];
			utils->array[utils->pivot_idx + 1] = utils->array[right];
			utils->array[right] = swap;
			print_array(utils->array, utils->size);
		}

		quick_sort_lomuto(array, utils->size, utils->left, utils->pivot_idx);
		quick_sort_lomuto(array, utils->size, utils->pivot_idx + 2, utils->right);
	}
}

/**
 * find_and_move_lesser_numbers - Finds numbers lesser than the pivot
 * @utils: Address of the struct containing data needed for finding and moving
 *
 * Description: Calls a function to move any lesser number if found
 */
void find_and_move_lesser_numbers(quick_sort_struct *utils)
{
	while (utils->curr_int_idx < utils->right)
	{
		if (utils->array[utils->curr_int_idx] <= utils->pivot)
		{
			utils->pivot_idx++;
			swap_numbers(utils);
		}
		utils->curr_int_idx++;
	}
}

/**
 * swap_numbers - Swaps two numbers in the array of integers
 * @utils: Address of struct containing necessery data to be used for swapping
 */
void swap_numbers(quick_sort_struct *utils)
{
	int swap;

	if (utils->curr_int_idx != utils->pivot_idx)
	{
		swap = utils->array[utils->pivot_idx];
		utils->array[utils->pivot_idx] = utils->array[utils->curr_int_idx];
		utils->array[utils->curr_int_idx] = swap;
		print_array(utils->array, utils->size);
	}
}
