#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Card suit
 * @SPADE: Spade
 * @HEART: Heart
 * @CLUB: Club
 * @DIAMOND: Diamond
 */
typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (Ace to King)
 * @kind: Suit of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node of a doubly linked list representing a deck
 * @card: Pointer to the card
 * @prev: Previous node
 * @next: Next node
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
