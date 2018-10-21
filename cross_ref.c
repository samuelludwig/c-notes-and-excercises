#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000
void copy(char to[], char from[]);
void define_noise(char string[][MAXSIZE]);
char *build_word(char initialchar);
bool is_noise(char string[], char noise_array[][MAXSIZE]);

typedef struct Word {
    char this_word[MAXSIZE];    // a chararray (string)- the word to be tracked 
    int lines_found[MAXSIZE];  // an array of integers indicating lines found
    struct word *next_word;
} Word;

int main(int argc, char const *argv[])
{
    char *word_array[MAXSIZE];
    char noise_words[MAXSIZE][MAXSIZE];
    define_noise(noise_words);

    Word word_bank[MAXSIZE];
    return 0;
}

void define_noise(char string[][MAXSIZE])
{
    printf("Define noise words, capitalization is irrelevant (input as alphanumeric words separated by blanks):\n");
    
    int c = ' ';
    int wordcounter = 0;
    while (c != EOF) {
        if (isalnum(c)) {
            char *word = build_word(c);

            int i;
            for (i = 0; word[i] != '\0'; i++){
                string[wordcounter][i] = word[i];
            }
            string[wordcounter][i+1] = '\0';
            wordcounter++;
        } else {
            c = getchar();
        }
    }

    printf("Restrictions defined...\n");
}

void traverse_file()
{
    int linenum = 0;

    int c = ' ';
    while(c != EOF){
        if (c == '\n') {
            linenum++;
        }

        
        if (isalnum(c)) {
            char *word = build_word(c);
        }    
    }
}

bool is_noise(char *string, char noise_words[][MAXSIZE])
{
    size_t noise_size = (sizeof(noise_words)/sizeof(noise_words[0][0]));
    for (int i = 0; i < noise_size; i++) {
        
    }

    return false;
}

char *build_word(char initialchar) 
{
    char word[MAXSIZE];
    for (int i = 0; isalnum(initialchar); i++) {
        word[i] = initialchar;
        initialchar = getchar();
        if (!isalnum(initialchar)) {
            word[i+1] = '\0';
        }
    }
    return word;
}