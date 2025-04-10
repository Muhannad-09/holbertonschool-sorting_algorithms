#include "deck.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: difference between first non-matching characters
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * card_value - assigns a numerical value to a card
 * @value: the string value of the card (e.g., "Ace", "10", "Jack")
 *
 * Return: the numeric value of the card (0 to 13)
 */
int card_value(const char *value)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
					  "8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (_strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * compare_cards - compares two cards
 * @a: first card
 * @b: second card
 *
 * Return: negative if a < b, positive if a > b, 0 if equal
 */
int compare_cards(const deck_node_t *a, const deck_node_t *b)
{
	int val_a = card_value(a->card->value);
	int val_b = card_value(b->card->value);

	if (val_a == val_b)
		return (a->card->kind - b->card->kind);
	return (val_a - val_b);
}

/**
 * swap_nodes - swaps two adjacent nodes in the deck
 * @deck: double pointer to the deck
 * @a: first node
 * @b: second node
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - sorts a deck of cards in place
 * @deck: double pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	int sorted;
	deck_node_t *current;

	if (!deck || !*deck || !(*deck)->next)
		return;

	do {
		sorted = 1;
		current = *deck;

		while (current->next)
		{
			if (compare_cards(current, current->next) > 0)
			{
				swap_nodes(deck, current, current->next);
				sorted = 0;
			}
			else
			{
				current = current->next;
			}
		}
	} while (!sorted);
}
