#include <stdio.h>

char lower(char c);

/* test lower function */
main()
{
  for (int i = 'A'; i <= 'Z'; ++i)
    printf("%c %c\n", lower(i), lower(lower(i)));
  return 0;
}

/* lower: convert upper case to lower case */
char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c - ('a' - 'A');
}
