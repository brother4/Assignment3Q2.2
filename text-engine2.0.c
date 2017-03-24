#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.h"
#include "levenshtein.h"

#define WORD_LENGTH 50

int main(int argc, char *argv[])
{
    FILE *dictionary = NULL;
    char userWord[WORD_LENGTH];
    char compareWord[WORD_LENGTH];
    dictionary = fopen(argv[1], "r");
    printf("What word should I check? \n");
    fgets(userWord, WORD_LENGTH, stdin);
    //removing the newline character
    userWord[strlen(userWord) - 1] = '\0';

    while(fgets(compareWord, WORD_LENGTH, dictionary) != NULL)
    {
        if (levenshtein(userWord, compareWord) < 5) 
        {
            insert(compareWord);
            printf("%s\n", compareWord);
        }
    }
    fclose(dictionary);

}