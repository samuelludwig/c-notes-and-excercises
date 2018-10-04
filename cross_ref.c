#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000

void define_noise(char);

int main(int argc, char const *argv[])
{
    char *noise_words[MAXSIZE]; // array of pointers to predetermined noise words
    define_noise(*noise_words);  // fills up array with pointers to noise words
    return 0;
}

/* 
    Write a cross referencer that prints a lits of all words in a document, 
    and, for each word a list of the line numbers on which it occurs. 
    remove noise words like "the", "and", etc.
*/

/*
    So-

    Routines/items needed:
        - loop through file comparing each word to the noise list, if not, update 'lines found'
        - check if noise
            - for each word, will loop through predefined array of 'noise words' and ignore if found in the array
        - line number incrementer for every '\n'
        - word struct with properties (the_word, appeared_lines)
            - appeared_lines will be a pointer to an array of ints
        - array to store pointers to every word object
            - array will be sorted alphabetically 
                - array will be a binary tree
*/

void define_noise(char *string[])
{
    printf("Define noise words, capitalization is irrelevant (input as alphanumeric words separated by blanks):\n");
    
    // begin iterating through the input using getchar()
    int c;
    char word[64];
    while((c = getchar()) != EOF) {

    /* 
        if we are reading a word (as opposed to a blank)
        build up the word character by character until a blank is reached
        as soon as the blank is reached the word has been completed, so we will store it into the string array for noise words
    */
        int wordpos = 0;
        while(isalnum(c)) {
            strcat(word[wordpos], c);
            wordpos++;
            c = getchar();
        }

        strcpy_s(string, sizeof(word), word);   // place word into array of noise words

        for (int i = 0; i < wordpos; i++) { // clear out word and set wordpos back to 0
            word[i] = " "; 
        }
        wordpos = 0;

        if(c == EOF) {  // one last check at the end before getchar is called at the top of the loop
            break;
        }
    }

}

void check_if_noise(char *string)
{

}

struct word {
    char this_word[MAXSIZE];    // a chararray (string)- the word to be tracked 
    int lines_found[];  // an array of integers indicating lines found
}