#include <stdio.h>
#include <limits.h>

long power(int, int);

/* determine the ranges of char, short, int, and long
 * variables, both signed and unsigned 
 */
int main(void)
{
	printf("Range of unsigned char:\n");
	printf("From Header: %d ~ %d\n", 0, UCHAR_MAX);
	printf("Direct Computation: %d ~ %d\n", 0, (int) power(2, CHAR_BIT) - 1);
	printf("Range of signed char:\n");
	printf("From Header: %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Direct Computation: %d ~ %d\n\n", (int) 0 - power(2, CHAR_BIT - 1),
						(int) power(2, CHAR_BIT - 1) - 1);

	printf("Range of unsigned short:\n");
	printf("From Header: %d ~ %d\n", 0, USHRT_MAX);
	printf("Direct Computation: %d ~ %d\n", 0, (int) power(2, 16) - 1);
	printf("Range of signed short:\n");
	printf("From Header: %d ~ %d\n", SHRT_MIN, SHRT_MAX);
	printf("Direct Computation: %d ~ %d\n\n", (int) 0 - power(2, 16 - 1),
						(int) power(2, 16 - 1) - 1);

	printf("Range of unsigned int:\n");
	printf("From Header: %u ~ %u\n", 0, UINT_MAX);
	printf("Direct Computation: %u ~ %u\n", 0, (unsigned int) power(2, 32) - 1);
	printf("Range of signed short:\n");
	printf("From Header: %d ~ %d\n", INT_MIN, INT_MAX);
	printf("Direct Computation: %d ~ %d\n\n", (int) 0 - power(2, 32- 1),
						(int) power(2, 32 - 1) - 1);

	return 0;
}

/* power: raise b to the nth power */
long power(int b, int n)
{
	long p = 1;

	while (n-- > 0)
		p *= b;
	return p;
}
