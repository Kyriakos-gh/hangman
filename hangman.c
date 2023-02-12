/*
    hangman.c : Simple Hangman game!
    Kyriakos, 12/2/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const char *SECRET_WORD = "banana";
    const unsigned short int SECRET_WORD_LEN = strlen(SECRET_WORD);
    char word[SECRET_WORD_LEN];
    char letter;

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