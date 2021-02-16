#include <stdio.h>

#define MAXWORDS 100	/* maximum number of words allowed */
#define MAXFREQ 20	/* maximum number of characters in a world */ 

/* print a vertical histogram of the lengths of words in its input */
main()
{
	int c;
	int i, j;
	int word_freq[MAXWORDS];

	for (i = 0; i < MAXWORDS; ++i)
		word_freq[i] = 0;

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			++i;
		else
			++word_freq[i];
	}

	for (j = MAXFREQ; j >= 1; --j) {
		for (i = 0; i < MAXWORDS; ++i) {
			if (word_freq[i] >= j)
				printf("| ");
			else
				printf("  ");
		}
		printf("\n");
	}
}
