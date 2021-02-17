#include <stdio.h>

#define MAXWORDS 100	/* maximum number of words allowed */
#define MAXLEN 20	/* maximum number of characters in a world */ 

/* print a vertical histogram of the lengths of words in its input */
main()
{
	int c;
	int i, j;
	int word_len[MAXWORDS];

	for (i = 0; i < MAXWORDS; ++i)
		word_len[i] = 0;

	i = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n')
			++i;
		else
			++word_len[i];
	}

	for (j = MAXLEN; j >= 1; --j) {
		for (i = 0; i < MAXWORDS; ++i) {
			if (word_len[i] >= j)
				printf("| ");
			else
				printf("  ");
		}
		printf("\n");
	}
}
