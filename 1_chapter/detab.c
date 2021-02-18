#include <stdio.h>
#include "myio.h"

#define TABSTOPS 8	/* number of columns in a tab */

void detab(char line[], int length);
void insert_nchar(char line[], int character, int index, int n, int length);

main()
{
	int len;
	char line[MAXLINE];

	while ((len = lineget(line, MAXLINE)) > 0) {
		detab(line, len);
		printf("%s", line);
	}
}

/* detab: converts tabs into appropriate spaces */
void detab(char s[], int len)
{
	int i;
	int column;
	int nspaces;

	i = 0;
	column = 1;
	while (s[i]) {
		if (s[i] == '\t') {
			s[i++] = ' ';
			nspaces = TABSTOPS - column;
			insert_nchar(s, ' ', i, nspaces, len);
			len += nspaces;
			i += nspaces;
			column = 0;
		} else {
			++i;
		}
		if (column < TABSTOPS)
			column++;
		else
			column = 1;
	}
}

/* insert_nchar: insert n characters starting from index i while
 * shifting other values */
void insert_nchar(char s[], int c, int index, int n, int len)
{
	while (index <= len)
		s[len+n] = s[len--];

	while (n-- > 0)
		s[index++] = c;
}
