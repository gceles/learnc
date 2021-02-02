#include <stdio.h>
#include <ctype.h>
#include <math.h>

int htoi(char hexnum[]);

/* converts string of hexadecimal digits (including optional 0x or 0X)
   into its equivalent integer value */
main()
{
  printf("0Xff: %d\n", htoi("0Xff"));
  printf("0xff: %d\n", htoi("0xff"));
  printf("0x12: %d\n", htoi("0x12"));
  printf("0Xaf: %d\n", htoi("0Xaf"));
  return 0;
}

/* htoi: convert s(hexcode) to integer and return it */
int htoi(char s[])
{
  int num, i, len, tmp;

  /* check for optional header */
  i = 0;
  if (tolower(s[1]) == 'x')
    i = 2;

  /* find length of the digit */
  len = 0;
  tmp = i;
  while (s[tmp] != '\0' && s[tmp] != '\n') {
    ++tmp;
    ++len;
  }

  /* compute the decimal equivalent */
  num = 0;
  len -= 1;
  while (len >= 0) {
    if (isdigit(s[i]))
      num = num + (s[i] - '0') * pow(16, len);
    else
      num = num + (tolower(s[i]) - 'a' + 10) * pow(16, len);
    ++i;
    --len;
  }

  return num;
}
