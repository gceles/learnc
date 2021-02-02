#include <stdio.h>

int any(char s1[], char s2[]);

/* demonstrate any(s1, s2) function */
main()
{
  char s1[] = "Shivang Shukla";
  char s2[] = "pokemon";

  printf("%d\n", any(s1, s2));
  return 0;
}

/* any: returns the first location in string s1 where any character
   from s2 occurs, otherwise return -1 */
int any(char s1[], char s2[])
{
  int i, j;

  j = 0;
  while(s2[j] != '\0') {
    i = 0;
    while(s1[i] != '\0') {
      printf("%d\n", i);
      putchar(s1[i]);
      if (s1[i] == s2[j])
	return i+1;
      ++i;
    }
    ++j;
  }
  return -1;
}
