#include "Card.H"
#include "Deck.h"

#define HAND_SIZE 10

int get_card_value(Card* card);
int get_hand_total_value(Card hand[], char player[]);
void print_card(Card currentCard, int i);
void deal_card(Card hand[], Deck* deck, int amount);

int get_hand_total_value(Card hand[], char player[]) {
    printf("%s hand: ", player);

    int sum = 0;
    int ace_count = 0;

    for (int i = 0; i < HAND_SIZE; i++) {
        Card currentCard = hand[i];
        if (currentCard.value != 0) {
            print_card(currentCard, i);
            if (currentCard.value == 1) ace_count++;

            sum += get_card_value(&currentCard);
            if (sum > 21 && ace_count > 0) {
                sum -= 10;
                ace_count--;
            }
        }
        // Simulate dealer face-down card
        if (i == 1 && currentCard.value == 0) {
            printf("[] ");
        }
    }
    printf(" %s total: %d\n", player, sum);
    return sum;
}

void print_card(Card currentCard, int i) {
    char suit = currentCard.suit[0];
    // J, Q, K, A
    if (currentCard.value == 1) {
        printf("A");
    }
    else if (currentCard.value == 11) {
        printf("J");
    }
    else if (currentCard.value == 12) {
        printf("Q");
    }
    else if (currentCard.value == 13) {
        printf("K");
    }
    else {
        printf("%d", currentCard.value);
    }
    wprintf(L"%lc ", suit);
}

int get_card_value(Card* card) {
    if (card->value > 10 && card->value < 14) return 10;
    else if (card->value == 1) {
        return 11;
    }
    return card->value;
}

void deal_card(Card hand[], Deck* deck, int amount) {
    for (int j = 0; j < amount; j++) {
        for (int i = 0; i < HAND_SIZE; i++) {
            if (hand[i].value == 0) {
                Card next_card_from_deck = deck->cards[deck->current_card_index++];
                hand[i] = next_card_from_deck;
                break;
            }
        }
    }
}
