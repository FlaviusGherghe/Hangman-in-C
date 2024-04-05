#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6
#define MAX_WORD_LENGTH 20
#define MAX_WORDS 6


int main()
{
    char words[MAX_WORDS][MAX_WORD_LENGTH] =
    {
        "apple", "banana", "orange", "grape", "melon", "strawberry"
    };

    time_t t;
    srand((unsigned)time(&t));
    printf("Words: ");


    for(int i = 0; i < MAX_WORDS; i++)
    {
        printf("%s\t\n", words[i]);
    }

    int numWords = sizeof(words) / sizeof(words[0]);
    int randomIndex = rand() % numWords;
    int guess;
    int tries = 0, score;

    while(tries < MAX_TRIES){
    printf("Enter your gueess ( 0 to %d): ", MAX_WORDS - 1);
    scanf("%d", &guess);



    if(guess == randomIndex)
    {
        printf("You won!!! The word is: %s\n", words[randomIndex]);
        ++tries;
        ++score;
        break;
    }
    else
    {
        printf("Incorrect word. Try again.\n", words[randomIndex]);
         ++tries;

    }
    if(tries == MAX_TRIES){
        printf("You lost. The correct word is: %s\n", words[randomIndex]);
        score--;
    }
    }

    return 0;
}
