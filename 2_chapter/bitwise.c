#include <stdio.h>

unsigned setbits(int, int, int, int);
unsigned inverse(int, int, int);
unsigned getbits(int, int, int);

/* test bitwise functions */
int main(void)
{
	int x = 0277;
	int y = 0222;
	int p = 5;
	int n = 3;

	printf("x = %d, y = %d, p = %d, n = %d\n", x, y, p, n);
	printf("After setting x: %d\n", setbits(x, p, n, y));
	printf("After inverting x: %d\n", inverse(x, p, n));
}

/* setbits: returns x with n bits that begin at position p set to the
 * rightmost n bits of y
 */
unsigned setbits(int x, int p, int n, int y)
{
	int mask;

	mask = (32767 << p+1) | ~(~0 << (p+1-n));
	x = x & mask;
	return x | (getbits(y, n-1, n) << (p+1-n));	
}


/* inverse: returns x with n bits that begin at position p inverted */
unsigned inverse(int x, int p, int n)
{
	return x ^ (~(~0 << (p+1-n)) << (p+1-n));
}

/* rightrot: returns the value of x rotated to the right by n bits */
unsigned rightrot(int x, int n)
{
}

/* getbits: get n bits from position p */
unsigned getbits(int x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}