#include <stdio.h>
#define TABSTOPS 8		/* number of columns in a tab */

/* replaces suitable strings of spaces with tabs */
main()
{
  int c, column, spaces;

  column = 1;
  spaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (column % TABSTOPS == 0 && spaces != 0) {
	putchar('\t');
	spaces = 0;
      }
      else
	++spaces;
    }
    else {
      while (spaces != 0) {
	putchar(' ');
	--spaces;
      }
      putchar(c);
    }
    ++column;
    if (c == '\n')
      column = 1;
  }
  return 0;
}
