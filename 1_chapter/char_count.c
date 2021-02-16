#include <stdio.h>

#define MAXCHAR 100	/* maximum characters allowed in input */
#define MAXFREQ 100	/* maximum frequency of a single character */

/* prints a histogram of frequency of different characters in input */
main()
{
	int c;
	int i, j;
	int char_freq[MAXCHAR];

	for (i = 0; i < MAXCHAR; ++i)
		char_freq[i] = 0;
	
	i = 0;
	while ((c = getchar()) != EOF)
		if (c != ' ' || c != '\t' || c != '\n')
			++char_freq[c - '!'];
	
	for (i = MAXFREQ; i >= 1; --i) {
		for (j = 0; j < MAXCHAR; ++j) {
			if (char_freq[j] >= i)
				printf("| ");
			else
				printf("  ");
		}
		printf("\n");
	}

	for (i = '!'; i <= '~'; ++i)
		printf("%c ", i);
	printf("\n");
}

