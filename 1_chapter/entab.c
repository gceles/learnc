#include <stdio.h>
#include "myio.h"

void entab(char line[], int len);

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
}
