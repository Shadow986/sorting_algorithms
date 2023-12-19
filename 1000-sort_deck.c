#include "deck.h"
#include <stdlib.h>

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
  if (deck == NULL || *deck == NULL)
        return;

    size_t num_cards = 52;
    card_t *cards = malloc(num_cards * sizeof(card_t));
    deck_node_t *current = *deck;

    if (cards == NULL)
        return;

    // Copy the cards from the deck to an array
    for (size_t i = 0; i < num_cards; i++)
    {
        cards[i] = *(current->card);
        current = current->next;
    }

    // Sort the array of cards using qsort
    qsort(cards, num_cards, sizeof(card_t), compare_cards);

    // Update the deck with the sorted cards
    current = *deck;
    for (size_t i = 0; i < num_cards; i++)
    {
        current->card = &cards[i];
        current = current->next;
    }

    free(cards);
}

/**
 * compare_cards - Comparison function for qsort
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative if card1 < card2, 0 if card1 == card2, Positive if card1 > card2
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = (const card_t *)card1;
    const card_t *c2 = (const card_t *)card2;

    int value_cmp = strcmp(c1->value, c2->value);
    if (value_cmp != 0)
        return value_cmp;

    return c1->kind - c2->kind;
}
