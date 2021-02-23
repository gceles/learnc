#include <ctype.h>
#include <math.h>

int lower(int c);

/* htoi: convert string of hexadecimal digits to integer equivalent */
int htoi(char s[])
{
	int i;
	int n;
	int len;

	len = 0;
	while (s[len] != '\0')
		++len;
	len--;			/* last digit's index */

	n = i = 0;
	while (len >= 0 && tolower(s[len]) != 'x') {
		if (isalpha(s[len])) {
			n += (tolower(s[len--]) - 'a' + 10) * pow(16,i);
		} else {
			n += (s[len--] - '0') * pow(16, i);
		}
		++i;
	}
	return n;
}
