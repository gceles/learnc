#include <stdio.h>

#define IN 0	/* inside a comment/quote */
#define OUT 1	/* outside a comment/quote */

/* removes comment from a C program */
main()
{
	int c;
	int comment;
	int quote;

	comment = quote = OUT;
	while ((c = getchar()) != EOF) {
		if (c == '\"') {
			if (comment == OUT)
				(quote == IN) ? (quote = OUT) : (quote = IN);
		} else if (c == '\\') {
			if (comment == OUT) {
				putchar(c);
				c = getchar();
			}
		} else if (quote == OUT) {
			if (comment == OUT) {
				if (c == '/') {
					c = getchar();
					if (c == '*')
						comment = IN;
					else
						putchar('/');
				}
			} else {
				if (c == '*') {
					c = getchar();
					if (c == '/') {
						comment = OUT;
						continue;
					}
				}
			}
		}

		if (comment == OUT)
			putchar(c);
	}
}