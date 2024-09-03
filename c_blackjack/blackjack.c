#include <stdio.h>
#include "Deck.H"
#include "Card.H"
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "blackjack.h"

void reset_game();

bool player_turn = true;
bool first_deal = true;
Card dealer_hand[HAND_SIZE] = { 0 };
Card player_hand[HAND_SIZE] = { 0 };

int main() {
    srand(time(NULL));
    Deck deck = create_deck();
    int player_card_value, dealer_card_value;

    char user_input;
    do {
        if (first_deal) {
            shuffle_deck(&deck);
            deal_card(player_hand, &deck, 2);
            deal_card(dealer_hand, &deck, 1);
            first_deal = false;
        }

        system("cls");
        user_input = 'k';
        player_card_value = get_hand_total_value(player_hand, "Your");
        dealer_card_value = get_hand_total_value(dealer_hand, "Dealer");

        if (player_card_value > 21) {
            printf("Dealer wins!\n");
            Sleep(2500);
            reset_game();
            continue;
        }

        if (player_turn) {
            printf("1. Deal a card\n");
            printf("2. Stay\n");
            printf("3. Quit\n");
            while (user_input != '1' && user_input != '2') {
                user_input = getch();

                if (user_input == '1') {
                    printf("Deal a card");
                    Sleep(1500);
                    deal_card(player_hand, &deck, 1);
                }
                else if (user_input == '2') {
                    printf("Stay");
                    player_turn = false;
                    Sleep(1500);
                }
                else if (user_input == '3') {
                    return 0;
                }
            }
        }

        // Dealer turn
        else {
            if (dealer_card_value < player_card_value && dealer_card_value < 17) {
                deal_card(dealer_hand, &deck, 1);
                Sleep(1500);
            }

            // Winner conditions
            else if (dealer_card_value > 21) {
                printf("You win");
                Sleep(2500);
                reset_game();
            }
            else if (dealer_card_value > player_card_value) {
                printf("Dealer wins!");
                Sleep(2500);
                reset_game();
            }
            else if (dealer_card_value < player_card_value) {
                printf("You Win!");
                Sleep(2500);
                reset_game();
            }
            else if (dealer_card_value == player_card_value) {
                printf("Its tie!");
                Sleep(2500);
                reset_game();
            }
        }
    } while (1);

}

void reset_game() {
    player_turn = true;
    first_deal = true;

    for (int i = 0; i < HAND_SIZE; i++) {
        player_hand[i].value = 0;
        dealer_hand[i].value = 0;
    }
}