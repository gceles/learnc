/* atoi: convert s to integer */
int atoi(char s[])
{
	int i;
	int n;

	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');
	return n;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}

/* If there are no unsigned operands, the following
 * informal set of rules will suffice:
 * 	If either operand is long double, convert the other to long double
 *	Otherwise, if either operand is double, convert the other to double
 *	Otherwise, if either operand is float, convert the other to float
 *	Otherwise, convert char and short to int
 *	Then, if either operand is long, convert the other to long.
 *
 *	In the absence of a function prototype, char and short become int, and float becomes double
 */

unsigned long int next = 1;

/* rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
	next = seed;
}