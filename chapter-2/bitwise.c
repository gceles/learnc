#include <stdio.h>

unsigned getbits(unsigned, int, int);
unsigned setbits(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);
int bitcount(unsigned x);

/* test some procedures created using bitwise operators */
main()
{
  unsigned x = 398; 			/* 110001110 */
  unsigned y = 421;			/* 110100101 */

  printf("Expected\t|\tComputed\n");
  printf("1\t\t|\t%u\n", getbits(x, 5, 3));
  printf("430\t\t|\t%u\n", setbits(x, 5, 3, y));
  printf("438\t\t|\t%u\n", invert(x, 5, 3));
  printf("7\t\t|\t%d\n", bitcount(7));
  
  return 0;
}

/* getbits: get n bits from the position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: set the n bits in x that begins at position p with the
   rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned src = ~(~0 << n) & y;
  /* set src's end n bits at position p */
  src = src << (p-n+1);
  /* set the n bits beginning at p in x to 0s */
  x = x & ~(~(~0 << n) << p-n+1);

  return x | src;
}

/* invert: invert n bits that begin at position p in x */
unsigned invert(unsigned x, int p, int n)
{
  return x ^ (~(~0 << n) << p-n+1);
}

/* rightrot: returns the value of x rotated to the right by n bits */
unsigned rightrot(unsigned x, int n)
{
  int tmp = x & ~(~0 << n);
  x = x >> n;
  return ;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
  int b = 0;
  if (x = 0)
    return b;
  while ((x &= (x-1)) > 0)
    ++b;
  return b;
}
