#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000
#define BANLIMIT 100

void copy(char to[], char from[]);
void pt_define_noise(char *string[]);
void build_word(char* pointer_to_word, char initialchar);
bool is_noise(char *string, char *noise_array[]);

struct word {
    char *this_word;    // a chararray (string)- the word to be tracked 
    int lines_found[MAXSIZE];  // an array of integers indicating lines found
    struct word *lword;
    struct word *rword; // pointers to the left and right children of this node
};

/*  
creates a brand new word struct, will be called if a non-noise word is 
processed in traverse_file function that doesn't exist inside the binary tree
*/
struct word *register_new_word(char *string) 
{
    struct word temp;

    strcpy(temp.this_word, string);
    temp.lines_found[0];
    temp.lword = NULL;
    temp.rword = NULL;
    return &temp;
}

int main(int argc, char const *argv[])
{
    char *word_array[MAXSIZE];
    char *noise_words[MAXSIZE];
    pt_define_noise(noise_words);
    
    
    
    printf("Word banned: %s", noise_words[0]);

    // struct word word_bank[MAXSIZE];
    return 0;
}

void pt_define_noise(char *string[]) // input comes in through command line, ends up in an array of pointers to strings
{
    printf("Define noise words, capitalization is irrelevant (input as alphanumeric words separated by blanks):\n");
// - input comes in through console as words separated by spaces
//   - iterate through input one character at a time
    int c = ' ';
    int banned_count = 0;
    size_t word_size = (sizeof(char) * MAXSIZE);
    
    /* ptr will point to a block in memory where we will house the array of noise words, pointers to the words will all be an offset of ptr */
    char *ptr = (char*) calloc(BANLIMIT, word_size);

    while (c != EOF) {
        if (isalnum(c)) {
            char spaceptr[MAXSIZE];
            build_word(spaceptr, c);
            strcpy_s(ptr, word_size, spaceptr);
            string[banned_count] = ptr;
            ptr += word_size;
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
            char *word;
            build_word(word, c);
        }    
    }
}

bool is_noise(char *string, char *noise_words[])
{
    size_t noise_size = (sizeof(*noise_words)/sizeof(noise_words[0]));
    for (int i = 0; i < noise_size; i++) {
        /*
          compare string to each entry in the list of noise words
          if a matching string is found in the array of noise words, return true
        */
       if(strcmp(*string, noise_words[i])) {
           return true;
       }
    }

    return false;
}

/* 
takes in the first character of a string, builds a chararray until it hits a blank, appends a null char,
returns a pointer to a chararray containing the word 
*/
void build_word(char ptr_to_word[MAXSIZE], char initialchar) 
{
    for (int i = 0; isalnum(initialchar); i++) {
        ptr_to_word[i] = initialchar;
        initialchar = getchar();
        if (!isalnum(initialchar)) {
            ptr_to_word[i+1] = '\0';
        }
    }
}