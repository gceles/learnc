#include <stdio.h>
#define	MAXLINE	1000 /* maximum input line length */

int lineget(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";	/* pattern to search for */

/* find all lines matching pattern */
main()
{
    char line[MAXLINE];
    int found = 0;

    while (lineget(line, MAXLINE) > 0)
	if (strindex(line, pattern) >= 0) {
	    printf("%s", line);
	    found++;
	}
    return found;
}

/* lineget: get line into s, return length */
int lineget(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
	s[i++] = c;
    if (c == '\n')
	s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\n'; i++) {
	for (j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++, k++)
	    ;
	if (k > 0 && t[k] == '\0')
	    return i;
    }
    return -1;
}

/* strrindex: return index of of last most occurence of t */
int strrindex(char s[], char t[])
{
    int i, j, k, pos;

    pos = -1;
    for (i = 0; s[i] != '\n'; i++) {
	for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
	    ;
	if (k > 0 && t[k] == '\0') {
	    pos = i;
	}
    }
    return pos;
}
