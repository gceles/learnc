#include <stdio.h>
#include <string.h>

/* printd: print n in decimal */
void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);
    putchar(n % 10 + '0');
}

/* itoa: convert an integer to a string */
void itoa(char s[], int n)
{
    static int i = 0;
    
    if (n / 10) {
        itoa(s, n / 10);
    }
    s[i++] = n % 10 + '0';
}