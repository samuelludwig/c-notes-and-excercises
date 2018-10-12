#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    int n;
    int array[6] = {1};

    int array_size = sizeof(array)/sizeof(array[0]);

    for (n = 0; ((n < array_size) && (getint(&array[n]) != EOF)); n++) {

    }

    for(int i = 0; i < array_size; i++) {
        printf("%d", array[i]);
    }
}

/* getint: get next integer from input into *pn */
int getint(int *pn) 
{
    int c = ' ';
    int sign = 0;

    while (isspace(c)) {
        c = getch(); // remove whitespace
    }

    if ((!isdigit(c)) && (c != EOF) && (c != '+') && (c != '-')) {
        ungetch(c); // not a number
        return 0;
    }

    sign = ((c == '-') ? -1 : 1);
    
    if ((c == '+') || (c == '-')) {
        c = getch();
    } 

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = ((10 * *pn) + (c - '0'));
    }

    *pn *= sign;

    if (c != EOF) {
        ungetch(c);
    } 

    return c;
}

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