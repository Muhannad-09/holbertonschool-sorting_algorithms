#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: pointer to head of list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	print_list(*list);
}

/**
 * cocktail_sort_list - sorts a doubly linked list using cocktail shaker sort
 * @list: pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr;
	int swapped = 1;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		curr = *list;

		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = 1;
			}
			else
				curr = curr->next;
		}

		if (!swapped)
			break;

		swapped = 0;
		curr = curr->prev;

		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
