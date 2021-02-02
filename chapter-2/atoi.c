#include <stdio.h>
#define MAXLINE 1000		/* maximum length of an input line */

int lineget(char line[], int maxline);
int atoi(char number[]);

/* converts string of digits to integer */
main()
{
  char num[MAXLINE];
  
  while (lineget(num, MAXLINE) > 0) /* while there is a line */
    printf("%d\n", atoi(num));	    /* convert and print it */
  
  return 0;
}

/* lineget: input a line into s and return its length */
int lineget(char s[], int lim)
{
  int i, c;

  /* keep storing characters until EOF, \n or limit is exceeded */
  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    s[i] = c;
  /* if the line ended with \n store it too */
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  /* finally store the null character */
  s[i] = '\0';
  
  return i;
}

/* atoi: convert s to integer */
int atoi(char s[])
{
  int sum, i;

  sum = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    sum = sum * 10 + (s[i] - '0');
  return sum;
}
