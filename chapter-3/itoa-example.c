#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);

/* test itoa function */
main()
{
    char s[20];
    itoa(-2147483648, s);
    printf("%s\n", s);
    return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    int i, sign, overflow;

    overflow = 0;
    if ((sign = n) < 0)     /* record sign */
	if (n != -2147483648)
	    n = -n;             /* make n positive */
	else {
	    n = -(++n);		/* convert 2147483647 */
	    overflow = 1;
	}
    i = 0;
    
    do {			/* generate digits in reverse order */
	s[i++] = n % 10 + '0'; 	/* get next digit */
    } while ((n /= 10) > 0);	/* delete it */
    if (sign < 0)
	s[i++] = '-';
    s[i] = '\0';

    if (overflow)
	++s[0];
    
    reverse(s);
}

/* reverse: reverse a string */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
    }
}
