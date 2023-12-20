#include "sort.h"

/**
  * sort_deck - a function that sorts a deck of cards.
  * @deck: Deck of card.
  * Return: void.
  */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *tmp = NULL, *h = NULL;

	if (!(deck) || !(*deck) || !((*deck)->next))
		return;
}
