#include "sort.h"

/**
 * cocktail_sort_list - Implements the cocktail shaker sort algorithm
 * @list: Address of the pointer to the head of the doubly linked list of ints
 */
void cocktail_sort_list(listint_t **list)
{
	int sorted;
	listint_t *tail_ref = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	if (!(*list)->next->next)
	{
		swap_list_of_two(list);
		return;
	}

	while (TRUE)
	{
		sorted = TRUE;
		tail_ref = bubble_forward(list, &sorted);
		if (sorted)
			break;

		sorted = TRUE;
		bubble_backward(list, tail_ref, &sorted);
		if (sorted)
			break;
	}
}

/**
 * swap_list_of_two - Swaps two nodes in a list of two if needed
 * @list: Address of the pointer to the head node
 */
void swap_list_of_two(listint_t **list)
{
	if ((*list)->next->n < (*list)->n)
	{
		(*list)->next->next = *list;
		(*list)->next->prev = NULL;
		(*list)->prev = (*list)->next;
		(*list)->next = NULL;
		*list = (*list)->prev;

		print_list(*list);
	}
}

/**
 * bubble_forward - Carries out bubble sort in the forward direction
 * @list: Address of the head pointer to the list of integers
 * @sorted: A flag to say whether our list is sorted or not
 *
 * Return: A reference to the last node in the list
 */
listint_t *bubble_forward(listint_t **list, int *sorted)
{
	listint_t *curr_node = NULL, *curr_prev = NULL, *next_to_bubble = NULL;

	for (curr_node = (*list)->next; curr_node->next; curr_node = next_to_bubble)
	{
		next_to_bubble = curr_node->next;
		curr_prev = curr_node->prev;

		if (curr_prev->n > curr_node->n)
		{
			*sorted = FALSE;

			curr_prev->next = curr_node->next;
			if (curr_node->next)
				curr_node->next->prev = curr_prev;

			curr_node->prev = curr_prev->prev;
			if (curr_prev->prev)
				curr_prev->prev->next = curr_node;
			else
				*list = curr_node;

			curr_prev->prev = curr_node;
			curr_node->next = curr_prev;

			print_list(*list);
		}
	}

	return (curr_node);
}

/**
 * bubble_backward - Carries out bubble sort in the backward direction
 * @list: Address of the head pointer to the list of integers
 * @tail_ref: A reference to the last node in the list
 * @sorted: A flag to say whether our list is sorted or not
 */
void bubble_backward(listint_t **list, listint_t *tail_ref, int *sorted)
{
	listint_t *curr_node = NULL, *curr_next = NULL, *next_to_bubble = NULL;

	for (curr_node = tail_ref->prev; curr_node; curr_node = next_to_bubble)
	{
		next_to_bubble = curr_node->prev;
		curr_next = curr_node->next;

		if (curr_node->n > curr_next->n)
		{
			*sorted = FALSE;

			if (curr_next->next)
				curr_next->next->prev = curr_node;

			curr_next->prev = curr_node->prev;
			if (curr_node->prev)
				curr_node->prev->next = curr_next;
			else
				*list = curr_next;

			curr_node->next = curr_next->next;
			curr_node->prev = curr_next;
			curr_next->next = curr_node;

			print_list(*list);
		}
	}
}
