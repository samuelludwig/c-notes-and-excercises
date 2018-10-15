#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXSIZE 1000
void copy(char to[], char from[]);
void define_noise(char *string[]);

int main(int argc, char const *argv[])
{
    char *word_array[MAXSIZE];
    char *noise_words[1];
    define_noise(noise_words);
    return 0;
}


// int getline(char string[], int lim)
// {
//     int c, i;

//     for (i = 0; ((i < lim-1) && ((c = gethchar()) != EOF) && (c != '\n')); i++) {
//         string[i] = c;
//     }

//     if (c == '\n') {
//         string[i] = c;
//         i++;
//     }
//     string[i] = '\0';
//     return i;
// }


// void copy(char to[], char from[]) 
// {
//     int i = 0;

//     while((to[i] = from[i]) != '\0') {
//         i++;
//     }
// }

void define_noise(char *string[])
{
    printf("Define noise words, capitalization is irrelevant (input as alphanumeric words separated by blanks):\n");
    
    int c = ' ';
    int wordcounter = 0;
    while (c != EOF) {
        if (isalnum(c)) {
            char word[MAXSIZE];
            for (int i = 0; isalnum(c); i++) {
                word[i] = c;
                c = getchar();
                if (!isalnum(c)) {
                    word[i+1] = '\0';
                }
            }
            //
            // then add word to string[] of noise words
            string[wordcounter] = *&word;
            //
        } else {
            c = getchar();
        }
    }

    printf("first word banned is : %s", *string[0]);
}

void traverse_file()
{

}

// bool is_noise(char *string, char *noise_words[])
// {
//     for (int i = 0; i < sizeof(noise_words); i++) {
//         if (strcmp(*string, *noise_words[i])) {
//             return true;
//         }
//     }

//     return false;
// }

void to_char_array(char input[]) 
{
    
}

// struct word {
//     char this_word[MAXSIZE];    // a chararray (string)- the word to be tracked 
//     int lines_found[];  // an array of integers indicating lines found
// }