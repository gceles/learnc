#include <stdio.h>

/* copy input to output, replacing strings of one more blanks
 * by a single blank
 */
main()
{
	int c;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			putchar(' ');
			while ((c = getchar()) == ' ')
				;
		}
		putchar(c);
	}
}
