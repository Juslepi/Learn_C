#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
    char choices[3][15] = { "Rock", "Paper", "Scissors" };
    int user_input;
    int user_score, bot_score = 0;

    while (1) {
        printf("Your score: %d, Bot score: %d\n", user_score, bot_score);
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("Your choice: ");
        scanf("%d", &user_input);
        int bot_choice = (rand() % 3) + 1;

        printf("You chose %s. Bot chose %s\n", choices[user_input - 1], choices[bot_choice - 1]);
        if (user_input == bot_choice) {
            printf("Its a tie!\n");
        }
        else if (user_input == 1) {
            if (bot_choice == 2) {
                printf("Bot wins!\n");
                bot_score = bot_score + 1;
            }
            else {
                printf("You win\n");
                user_score = user_score + 1;
            }
        }
        else if (user_input == 2) {
            if (bot_choice == 1) {
                printf("You win\n");
                user_score = user_score + 1;
            }
            else {
                printf("Bot wins!\n");
                bot_score = bot_score + 1;
            }
        }
        else if (user_input == 3) {
            if (bot_choice == 1) {
                printf("Bot wins!\n");
                bot_score = bot_score + 1;
            }
            else {
                printf("You win!\n");
                user_score = user_score + 1;
            }
        }
        printf("Press Any Key to Continue\n");
        getch();
        printf("\e[1;1H\e[2J");
    }
}