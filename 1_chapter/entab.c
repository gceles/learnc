#include <stdio.h>
#include "myio.h"

#define TABSTOPS 8	/* number of columns in a tab */

void entab(char line[], int len);
void snip(char line[], int start, int end);

/* demonstrate entab() */
int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = lineget(line, MAXLINE)) > 0) {
		entab(line, len);
		printf("%s", line);
	}
	return 0;
}

/* entab: replaces appropriate sequences of spaces with tabs */
void entab(char s[], int len)
{
	int i;
	int column;	/* current column */
	int spaces;	/* number of consecutive spaces */

	column = 1;
	i = spaces = 0;
	while(s[i]) {
		if (s[i] == ' ') {
			++spaces;
			if (spaces > 1 && column == TABSTOPS) {
				i = i - spaces + 1;
				s[i] = '\t';
				snip(s, i + 1, i + 1 + spaces);
				column = 0;
				spaces = 0;
			}
			else if (column == TABSTOPS) {
				s[i] = ' ';
				column = 0;
				spaces = 0;
			}
		} else {
			spaces = 0;
		}
		++column;
		++i;
	}
}

/* snip: remove elements of string starting from i, until e (excluded) */
void snip(char s[], int i, int e)
{
	e--;
	while (s[i++] = s[e++])
		;
}
