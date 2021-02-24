#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(void)
{
	char s[1000];
	char t[1000] = "Hello!\t This is a tab. \n this is a newline";
	escape (s, t);
	printf("%s\n", s);
	unescape(t, s);
	printf("%s\n", t);

	return 0;
}

/* escape: converts characters like tabs and newline into visible
 * escape sequences like \t and \t as it copies the string t to s
 */
void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
		case '\t':
			s[j++] = '\\';
			s[j++] = 't';
			break;
		case '\n':
			s[j++] = '\\';
			s[j++] = 'n';
			break;
		default:
			s[j++] = t[i];
			break;
		}
		++i;
	}
	s[j] = '\0';
}

/* unescape: undo the escape() */
void unescape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0') {
		if (t[i] == '\\') {
			switch (t[++i]) {
			case 't':
				s[j++] = '\t';
				break;
			case 'n':
				s[j++] = '\n';
				break;
			default:
				s[j++] = '\\';
				s[j++] = t[i];
			}
		} else {
			s[j++] = t[i];
		}
		i++;
	}
	s[j] = '\0';
}