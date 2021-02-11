#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

/* test getint() */
main()
{
    int n = 0, c;
    while (getint(&n) != EOF)
        printf("You entered %d.\n", n);
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = getch()))	/* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);	/* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c  == '-')
        c = getch();
    if (!isdigit(c) && c != EOF) {
        if (sign == -1)
            ungetch('-');
        else
            ungetch('+');
        return 0;
    }
    for(*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int pushback = EOF;

int getch(void)	/* input a (possibly pushed-back) character */
{
    int c;
    if (pushback != EOF) {
        c = pushback;
        pushback = EOF;
        return c;
    }
    else
        return getchar();
}

void ungetch(int c)	/* pushback a character back to input */
{
    pushback = c;
}