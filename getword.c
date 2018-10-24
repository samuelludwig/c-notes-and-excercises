#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) 
{
    return ((bufp > 0) ? buf[--bufp] : getchar());
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}
/*---^---^---^--- USES ---^---^---^---*/



/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while(isspace(c = getchar()));

    if (c != EOF) {
        *w++ = c;
    }

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
        *w = '/0';
        return word[0];
    }
}