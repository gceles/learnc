#include <stdio.h>

#define MAXLINE	1000	/* maximum length of a line */

int lineget(char line[], int maxline);
void trim(char line[], int length);

/* remove trailing blanks, tabs and entirely blank lines */
int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = lineget(line, MAXLINE)) > 0) {
		trim(line, len);
		printf("%s", line);
	}
}

/* lineget: stores input line into s, return length */
int lineget(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

/* trim: remove trailing blanks and tabs from each of input */
void trim(char s[], int len)
{
	len -= 2;
	while (len >= 0 && s[len] == ' ' || s[len] == '\t')
		--len;
	if (len < 0) {
		s[0] = '\0';
	} else {
		s[len++] = '\n';
		s[len] = '\0';
	}
}
