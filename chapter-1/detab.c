#include <stdio.h>
#define TABSTOPS 8		/* number of columns in a tab */

/* replaces tabs with appropriate number of spaces */
main()
{
  int c, column;

  column = 1;
  while ((c=getchar()) != EOF) {
    /* if a tab is found */
    if (c == '\t') {
      /* print blanks till next tabstop */
      while (column % TABSTOPS != 0) {
	putchar(' ');
	++column;
      }
      putchar(' ');
    }
    else
      putchar(c);
    ++column;

    if (c == '\n')
      column = 1;
  }
  return 0;
}
