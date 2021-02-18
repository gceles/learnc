#include <stdio.h>

/* reverse: reverse a string */
void reverse(char s[])
{
	int i;
	int j;
	int tmp;

	i = j = 0;
	while (s[j] != '\0')
		++j;
	--j;

	while (i < j) {
		tmp = s[i];
		s[i++] = s[j];
		s[j--] = tmp;
	}
}
