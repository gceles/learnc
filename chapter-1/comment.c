#include <stdio.h>
#define IN  0			/* inside something */
#define OUT 1			/* outside something */

/* removes comments from a C program */
main()
{
  int c, quotes, comment;

  quotes = comment = OUT;
  while ((c = getchar()) != EOF) {
    /* sets a flag if inside quotes while outside a comment */
    if (c == '"' && comment == OUT)
      if (quotes == IN)
	quotes = OUT;
      else
	quotes = IN;
    /* if outside quotes, check for comments */
    if (quotes == OUT) {
      if (comment == OUT) {
	if (c == '/')
	  if ((c = getchar()) == '*')
	    comment = IN;
	  else
	    putchar('/');
      } else {
	if (c == '*')
	  if ((c = getchar()) == '/') {
	    comment = OUT;
	    c = getchar();
	  }
      }
    }
    if (comment == OUT)
      putchar(c);
  }
  return 0;
}
