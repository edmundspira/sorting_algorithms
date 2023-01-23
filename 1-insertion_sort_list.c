#include "sort.h"

/**
 * insertion_sort_list - Implementation of insertion sort algorithm in dll
 * @list: Address to the start of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *current_prev = NULL, *next_to_insert = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		current_prev = current->prev;
		next_to_insert = current->next;
		insertion_sort(list, current, current_prev);
		current = next_to_insert;
	}
}

/**
 * insertion_sort - Sorts the doubly linked list
 * @list: Address to the head of the list
 * @current: Current item to sort
 * @curr_prev: Item that comes before the current one on the list
 */
void insertion_sort(listint_t **list, listint_t *current, listint_t *curr_prev)
{
	while (curr_prev && curr_prev->n > current->n)
	{
		curr_prev->next = current->next;
		if (current->next)
			current->next->prev = curr_prev;
		current->prev = curr_prev->prev;
		if (curr_prev->prev)
			curr_prev->prev->next = current;
		else
			*list = current;
		curr_prev->prev = current;
		current->next = curr_prev;
		print_list(*list);
		curr_prev = current->prev;
	}
}
