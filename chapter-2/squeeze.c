#include <stdio.h>

void squeeze(char s1[], char s2[]);

/* demonstrate squeeze function */
main()
{
  char s1[] = "Hello, Wassup!";
  char s2[] = "luw";
  squeeze(s1, s2);
  printf("%s\n", s1);
  return 0;
}

/* squeeze: deletes each character in s1 that matches any character
   in s2 */
void squeeze(char s1[], char s2[])
{
  int i, j, k;

  k = 0;
  while (s2[k] != '\0') {
    for (i = j = 0; s1[i] != '\0'; ++i)
      if (s1[i] != s2[k])
	s1[j++] = s1[i];
    ++k;
    s1[j] = '\0';
  }
}
