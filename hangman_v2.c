/*
    hangman_v2.c : Simple Hangman game!
    Kyriakos, 12/2/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
    char letter;
    unsigned short int secret_word;
    const char *WORDS[] = {"computer", "tree", "banana", "sky", "cat", "compiler", "toy", "human", "color", "car"};

    srand(time(NULL));
    secret_word = rand() % 10;

    const char *SECRET_WORD = WORDS[secret_word];
    const unsigned short int SECRET_WORD_LEN = strlen(WORDS[secret_word]);
    char word[SECRET_WORD_LEN];

    memset(word, '_', SECRET_WORD_LEN);
    printf("Welcome to the Hangman game!\n");
    while(1) {
        printf("Please enter a letter:\n");
        fflush(stdout);
        scanf(" %c", &letter);
        for(unsigned short int i = 0; i < SECRET_WORD_LEN; i++) {
            if(SECRET_WORD[i] == letter) {
                word[i] = letter;
            }
        }
        printf("The word now is: %s\n", word);
        if(!strchr(word, '_')) {
            printf("congratulations! You found the word!");
            exit(0);
        }
    }
    return 0;
}
