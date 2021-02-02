#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

/* demonstrate other functions */
main()
{
  char t[] = {'G', 'a', 'u', '\t', 'r', '\n', 'a', 'n',
    'g', '\n', '\0'};
  char s[20];

  escape(s, t);
  printf("%s\n", s);
  unescape(t, s);
  printf("%s\n", t);
  return 0;
}

/* escape: converts characters like tabs and newlines into visible
   escape sequences like \t and \n */
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

/* unescape: reverse escape */
void unescape(char s[], char t[])
{
  int i, j;

  i = j = 0;
  while (t[i] != '\0') {
    if (t[i] == '\\') {
      switch (t[++i]) {
      case 't':
	s[j++] = '\t';
	++i;
	break;
      case 'n':
	s[j++] = '\n';
	++i;
	break;
      }
    }
    else {
      s[j++] = t[i++];
    }
  }
  s[j] = '\0';
}
