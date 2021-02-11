#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getfloat(float *);

/* test getint() */
main()
{
    float n = 0;
    int c;
    while ((c=getfloat(&n)) != EOF && c != 0)
        printf("You entered %.8g.\n", n);
    return 0;
}

/* getfloat: get next float from input onto *pn */
int getfloat(float *pn)
{
    int c, sign, decimal;
    /* get rid of white spaces */
    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
        ungetch(c);	/* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+')
        c = getch();
    /* get integer part */
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    decimal = 1;
    if (c != '.') {
        if (c == EOF)
            return c;
        else
            ungetch(c);
        return c;
    }
    /* get decimal part */
    while (isdigit(c = getch())) {
        decimal *= 10;
        *pn = 10 * *pn + (c - '0');
    }
    *pn /= decimal;
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