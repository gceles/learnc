/* squeeze: deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k;

	i = 0;
	while (s2[i] != '\0') {
		j = k = 0;
		while (s1[j] != '\0') {
			if (s1[j] != s2[i])
				s1[k++] = s1[j++];
			else
				j++;
		}
		s1[k] = '\0';
		i++;
	}
}