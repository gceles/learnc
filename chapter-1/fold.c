#include <stdio.h>
#define MAXLINE 1000		/* maximum length of a line */
#define NFOLD 20		/* fold length */

int lineget(char line[], int maxline);
void folder(char line[], int start);

/* fold long lines into multiple ones */
main()
{
  char line[MAXLINE];

  while (lineget(line, MAXLINE) > 0)
    folder(line, 0);
  return 0;
}

/* lineget: inputs a line in s, returns length */
int lineget(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* folder: fold lines using recursion */
void folder(char line[], int start)
{
  int i = start;
  int last_space = -1;
  int column = 1;
  while (1 == 1) {
    if (line[i] == ' ' || line[i] == '\n') {
      last_space = i;
      while (start < last_space) {
	putchar(line[start]);
	++start;
      }
    }
    if (column >= NFOLD) {
      if (last_space != -1)
	start = last_space + 1;
      else {
	while (start < i) {
	  putchar(line[start]);
	  ++start;
	}
      }
      putchar('\n');
      folder(line, start);
      return;
    }
    else if (line[i] == '\n')
      putchar('\n');
    if (line[i] == '\0')
      return;
    ++i;
    ++column;
  }
}
