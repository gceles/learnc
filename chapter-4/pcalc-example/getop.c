#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    
    static int tmp = EOF;

    if (tmp != EOF) {
        c = tmp;
        tmp = EOF;
    }
    else
        c = getch();

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;	/* not a number */
    i = 0;
    if (isdigit(c))	/* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')	/* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        tmp = c;
    return NUMBER;
}