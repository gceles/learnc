#include <stdio.h>

/* replaces tabs with the symbol '\t' */
main()
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t')
      printf("\\t");
    else
      putchar(c);
  }
  return 0;
}
