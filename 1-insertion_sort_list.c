#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using an insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *first, *second, *new, *temp;

	if (!list || !(*list) || !((*list)->next))
		return;

	first = (*list);
	second = (*list)->next;
	while (second)
	{
		new = second->next;
		while (first && second->n < first->n)
		{
			if (first->prev)
				first->prev->next = second;
			else
				*list = second;
			if (second->next)
				second->next->prev = first;
			temp = second->next;
			second->next = first;
			second->prev = first->prev;
			first->next = temp;
			first->prev = second;
			print_list(*list);
			first = second->prev;
		}
		second = new;
		if (second)
			first = second->prev;
	}
}
