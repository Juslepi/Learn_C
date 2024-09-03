#include "blackjack.h"
#include "Card.H"
#include <stdio.h>
#include <assert.h>
#include "Deck.h"

Card player_hand[HAND_SIZE] = { 0 };

void test_ace();
void clear_hand(Card hand[]);

int main() {
    Deck deck = create_deck();
    test_ace(deck);
}

void test_ace(Deck deck) {
    player_hand[0] = deck.cards[0];
    player_hand[1] = deck.cards[13];
    player_hand[2] = deck.cards[12];
    int sum = get_hand_total_value(player_hand, "Player");
    assert(sum == 12);

    player_hand[0] = deck.cards[0];
    player_hand[1] = deck.cards[13];
    player_hand[2] = deck.cards[26];
    player_hand[3] = deck.cards[39];
    sum = get_hand_total_value(player_hand, "Tester");
    assert(sum == 14);

    clear_hand(player_hand);

    player_hand[0] = deck.cards[0];
    player_hand[1] = deck.cards[12];
    sum = get_hand_total_value(player_hand, "Tester");
    assert(sum == 21);
}

void clear_hand(Card hand[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i].value = 0;
    }
}