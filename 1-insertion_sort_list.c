#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: First node
 * @b: Second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b || a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	b->next = a;
	a->prev = b;

	print_list(*list);
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		prev = current->prev;

		while (prev && current->n < prev->n)
		{
			swap_nodes(list, prev, current);
			prev = current->prev;
		}
		current = current->next;
	}
}
