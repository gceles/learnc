#include <stdio.h>
#include <ctype.h>

#define MAXIN  50		/* maximum length of input */
#define MAXOUT 1000		/* maximum length of output */

int lineget(char s[], int maxline);
void expand(char s1[], char s2[]);

/* demonstrate expand() */
main()
{
  char in[MAXIN];
  char out[MAXOUT];

  while (lineget(in, MAXIN) > 0) {
    expand(in, out);
    printf("%s\n", out);
  }
  return 0;
}

/* lineget: input a line into s, returns length */
int lineget(char s[], int lim)
{
  int i, c;

  for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  return i;
}

/* expand: expand string s1 consisting of sequences like a-z, 0-9 to
   abc..xyz in s2 */
void expand(char s1[], char s2[])
{
  int i, j;

  i = j = 0;
  while (s1[i] != '\0') {
    if (isdigit(s1[i])) {
      if (s1[i+1] == '-' && isdigit(s1[i+2]) && s1[i+2] >= s1[i]) {
	for (int c = s1[i]; c <= s1[i+2]; c++)
	  s2[j++] = c;
	i += 3;
      }
      else {
	s2[j++] = s1[i++];
      }
    }
    else if (isalpha(s1[i])) {
      if (s1[i+1] == '-' && isalpha(s1[i+2]) && s1[i+2] >= s1[i]) {
	for (int c = s1[i]; c <= s1[i+2]; c++)
	  s2[j++] = c;
	i += 3;
      }
      else {
	s2[j++] = s1[i++];
      }
    }
    else {
      s2[j++] = s1[i++];
    }
  }
  s2[j] = '\0';
}
