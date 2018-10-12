#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

int main(void) 
{

}

/* getline: get line into string, return length */
int getline(char string[], int lim)
{
    int c;
    int i;

    i = 0;
    while ((--lim > 0) && ((c = getchar()) != EOF) && (c != '\n')) {
        string[i] = c;
        i++;
    }

    if (c == '\n') {
        string[i] = c;
        i++;
    }

    string[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char* string[], int t)
{
    for (int i = sizeof(string); i > 0; i--) {
        if (string[i] == t) {
            return i;
        }
    }
    
    return -1;
}