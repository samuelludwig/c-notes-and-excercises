#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000
#define BANLIMIT 100
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void copy(char to[], char from[]);
void pt_define_noise(char *string[]);
void build_word(char* pointer_to_word, char initialchar);
bool is_noise(char *string, char *noise_array[]);
void traverse_file(char *noise_words[]);

struct tnode {
    char *word;    // a chararray (string)- the word to be tracked
    int times_encountered;
    int lines_found[MAXSIZE]; // an array of integers indicating lines found
    struct tnode *ltnode;
    struct tnode *rtnode; // pointers to the left and right children of this node
};

struct tnode *talloc(void) 
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *stringdup(char *s)   /* make a duplicate of s */
{
    char *p;

    p = (char *) malloc(strlen(s)+1);   /* +1 for '\0' */
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

/*  
creates a brand new word struct, will be called if a non-noise word is 
processed in traverse_file function that doesn't exist inside the binary tree
*/
struct tnode *register_word(struct tnode *ptr, char *string, int linenum) 
{
    int cond;

    if (ptr == NULL) {    /* a new word has arrived */
        ptr = talloc();   /* make a new node */
        ptr->word = stringdup(string);
        ptr->times_encountered = 1;
        ptr->lines_found[0] = linenum; 
        
        ptr->ltnode = ptr->rtnode = NULL;
    } else if ((cond = strcmp(string, ptr->word)) == 0) {
        ptr->times_encountered++;  /* repeated word */
        ptr->lines_found[(ptr->times_encountered) - 1] = linenum;
    } else if (cond < 0) {      /* if less than, go into left subtree */
        ptr->ltnode = register_word(ptr->ltnode, string, linenum);
    } else {    /* if greater than, go into right subtree */
        ptr->rtnode = register_word(ptr->rtnode, string, linenum);
    }

    return ptr;
}

int main(int argc, char const *argv[])
{
    char *word_array[MAXSIZE];
    char *noise_words[MAXSIZE];
    pt_define_noise(noise_words);
    
    printf("Words banned:\n");
    for (int i = 0; i < (NELEMS(*noise_words)); i++) {
        printf("%s\n", noise_words[i]);
    }

    printf("Input file stream:\n");
    traverse_file(noise_words);



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

/* moves through input provided through command line, and builds the binary tree of words, 
calls is_noise, build_word, and register_word functions */
void traverse_file(char *noise_words[]) 
{
    struct tnode *root;

    int linenum = 0;

    int c = ' ';
    while(c != EOF){
        if (c == '\n') {
            linenum++;
        }
  
        if (isalnum(c)) {
            char *word;
            build_word(word, c);

            if (!is_noise(word, noise_words)) {
                // test to see if word is in tree
                // if so, add linenum to word.lines_appeared[]
                // else, create a new node in the tree
                struct tnode *nextnode = register_word(root, word, linenum);
            }
        }  

        c = getchar();  
    }
}

bool is_noise(char *string, char *noise_words[])
{
    // size_t noise_size = (sizeof(noise_words)/sizeof(noise_words[0]));
    for (int i = 0; i < NELEMS(*noise_words); i++) {
        /*
          compare string to each entry in the list of noise words
          if a matching string is found in the array of noise words, return true
        */
       if(strcmp(string, noise_words[i])) {
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