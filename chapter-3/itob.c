#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char s[]);
void itob(int n, char s[], int b);

/* test itoa function */
main()
{
    char s[1000];
    int n, b;

    do {
	printf("Enter Number: ");
	scanf("%d", &n);
	printf("Base: ");
	scanf("%d", &b);

	itob(n, s, b);

	printf("%d in base %d is:\n%s\n", n, b, s);
    } while (1);
    return 0;
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

/* itob: convert integer n into base b and store it in string s */
void itob(int n, char s[], int b)
{
    int i, negative;

    i = negative = 0;
    switch (b) {
	case 2:
	    if (n < 0) {
		negative = 1;	/* record sign */
		n = -n;		/* make n positive */
		n--;		/* decrement it by 1 */
	    }
	    do {		/* generate bits in reverse order */
		if (n % 2 == 0)
		    s[i++] = '0';
		else
		    s[i++] = '1';
	    } while ((n /= 2) > 0);

	    /* fill the remaining bits with 0s */
	    while (i < 32)
		s[i++] = '0';
	    
	    if(negative) {
		i = 0;
		/* find 1's complement of the binary number */
		while (s[i] != '\0') {
		    if (s[i] == '1')
			s[i++] = '0';
		    else
			s[i++] = '1';
		}
	    }	

	    s[i] = '\0';
	    reverse(s);
	    break;
	case 8:
	    if (n < 0) {
		negative = 1;
		n = -n;
	    }
	    do {
		s[i++] = n % 8 + '0';
	    } while ((n /= 8) > 0);
	    if (negative)
		s[i++] = '-';
	    s[i] = '\0';
	    reverse(s);
	    break;
	case 16:
	    if (n < 0) {
		negative = -1;
		n = -n;
	    }
	    do {
		if (n % 16 <= 9)
		    s[i++] = n % 16 + '0';
		else
		    s[i++] = n % 16 - 10 + 'A';
	    } while ((n /= 16) > 0);
	    if (negative)
		s[i++] = '-';
	    s[i] = '\0';
	    reverse(s);
	    break;
	default:
	    itoa(n, s);
	    break;
    }
}
