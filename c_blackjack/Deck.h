#include "Card.H"
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#ifndef DECK_H
#define DECK_H

#define CARDS_IN_DECK 52

typedef struct Deck {
    Card cards[52];
    int current_card_index;
} Deck;

Deck create_deck() {
    Deck deck;
    
    char SUITS[4][20] = { "\x03", "\x06", "\x05", "\x04" };
    deck.current_card_index = 0;

    int suite_selector = 0;
    int card_value = 0;
    for (int i = 0; i < CARDS_IN_DECK; i++) {
        card_value++;
        if (card_value == 14) {
            card_value = 1;
            suite_selector++;
        }

        char suit[20];
        strcpy(suit, SUITS[suite_selector]);

        Card card = create_card(suit, card_value);
        deck.cards[i] = card;
    }
    return deck;
} 

void shuffle_deck(Deck* deck) {
    for (int i = 0; i < 1000; i++) {
        int y = (rand() % (CARDS_IN_DECK));
        int x = (rand() % (CARDS_IN_DECK));

        Card tmp = deck->cards[x];
        deck->cards[x] = deck->cards[y];
        deck->cards[y] = tmp;
    }
}

#endif // DECK_H