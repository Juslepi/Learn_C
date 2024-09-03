#ifndef CARD_H
#define CARD_H

#include <stdio.h>
#include <string.h>

typedef struct Card
{
    char suit[20];
    int value;
} Card;

Card create_card(char suit[20], int value) {
    Card card;
    strcpy(card.suit, suit);
    card.value = value;

    return card;
}

#endif // CARD_H