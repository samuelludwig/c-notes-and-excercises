#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000
#define BANLIMIT 100

void copy(char to[], char from[]);
void pt_define_noise(char *string[]);
char *build_word(char initialchar);
bool is_noise(char string[], char noise_array[][MAXSIZE]);

struct word {
    char *this_word;    // a chararray (string)- the word to be tracked 
    int lines_found[MAXSIZE];  // an array of integers indicating lines found
    struct word *lword;
    struct word *rword; // pointers to the left and right children of this node
};

int main(int argc, char const *argv[])
{
    char *word_array[MAXSIZE];
    char *noise_words[MAXSIZE];
    pt_define_noise(noise_words);
    printf("Word banned: %s", noise_words[0]);

    // struct word word_bank[MAXSIZE];
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

void pt_define_noise(char *string[]) // input comes in through command line, ends up in an array of pointers to strings
{
// - input comes in through console as words separated by spaces
//   - iterate through input one character at a time
    int c = ' ';
    int banned_count = 0;
    size_t word_size = (sizeof(char) * MAXSIZE);
    
    /* ptr will point to a block in memory where we will house the array of noise words, pointers to the words will all be an offset of ptr */
    char *ptr = (char*) calloc(BANLIMIT, word_size);

    while (c != EOF) {
        if (isalnum(c)) {
            char *spaceptr = build_word(c);
            strcpy_s(ptr, word_size, spaceptr);
            string[banned_count] = ptr;
            ptr++;
            banned_count++;
        }
        c = getchar();
    }    
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

// bool is_noise(char *string, char noise_words[][MAXSIZE])
// {
//     size_t noise_size = (sizeof(noise_words)/sizeof(noise_words[0][0]));
//     for (int i = 0; i < noise_size; i++) {
        
//     }

//     return false;
// }

/* takes in the first character of a string, builds a chararray until it hits a blank, appends a null char,
 returns a pointer to a chararray containing the word */
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