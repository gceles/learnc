#include <stdio.h>

void squeeze(char s1[], char s2[]);

/* test squeeze() */
int main(void)
{
	char s1[] = "Hello wassup!";
	char s2[] = "lsa";
	squeeze(s1, s2);
	printf("%s\n", s1);
	return 0;
}