/* any: returns the first location in s1 where any character from s2 occurs,
 * or -1 if s1 does not contain any character from s2
 */
int any(char s1[], char s2[])
{
	int i, j;

	i = 0;
	while (s1[i] != '\0') {
		j = 0;
		while (s2[j] != '\0')
			if (s2[j++] == s1[i])
				return i;
		i++;
	}
	return -1;
}