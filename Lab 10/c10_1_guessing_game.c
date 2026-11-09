#include <stdio.h>

int main(void) {
    int student_id_N = 1234;
    int secret = student_id_N % 100;
    
    int guess;
    int guess_count = 0;
    int max_guesses = 10;
    int game_over = 0;

    printf("=== Number Guessing Game ===\n");
    printf("Guess the secret number between 0 and 99 (Max %d attempts).\n\n", max_guesses);

    while (!game_over) {
        do {
            printf("Enter valid guess (0-99): ");
            scanf("%d", &guess);
            if (guess < 0 || guess > 99) {
                printf("Invalid! Guess must be between 0 and 99.\n");
            }
        } while (guess < 0 || guess > 99);

        guess_count++;

        if (guess == secret) {
            printf("\nCongratulations! You found the secret number %d in %d guesses!\n", secret, guess_count);
            game_over = 1;
        } else if (guess < secret) {
            printf("Too low!\n");
        } else {
            printf("Too high!\n");
        }

        if (!game_over && guess_count >= max_guesses) {
            printf("\nOut of guesses! You reached the limit of %d attempts.\n", max_guesses);
            printf("The secret number was %d.\n", secret);
            game_over = 1;
        }
    }

    return 0;
}
