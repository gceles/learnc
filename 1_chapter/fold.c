#include <stdio.h>
#include "myio.h"

#define FOLD 10		/* length at which lines are folded */

void insert_char(char line[], int c, int index);
void fold_line(char line[]);

int main(void)
{
	char line[MAXLINE];

	while (lineget(line, MAXLINE) > 0) {
		fold_line(line);
		printf("%s", line);
	}
	return 0;
}

/* fold_line: fold longer lines by inserting newlines */
void fold_line(char line[])
{
	int i;
	int length;	/* length of current line */
	int newline;	/* index where line is folded */

	newline = -1;
	i = length = 0;
	while (line[i]) {
		++length;

		if (line[i] == '\n') {
			newline = -1;
			length = 0;
		} else if (line[i] == ' ') {
			newline = i;
		}

		if (length > FOLD) {
			if (newline != -1) {
				line[newline] = '\n';
				length = 0;
				i = newline;
				newline = -1;
			} else {
				insert_char(line, '\n', i);
				newline = -1;
				length = 0;
			}
		}
		++i;
	}
}

/* insert_char: insert a character c at index i in s[] */
void insert_char(char s[], int c, int i)
{
	int len;

	len = 0;
	while (s[len])
		len++;

	while (len >= i)
		s[len+1] = s[len--];

	s[i] = c;
}
