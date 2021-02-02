main()
{
  int i = 0;
  int valid = 1;
  while (valid) {
    if (i >= lim-1)
      valid = 0;
    else if ((c = getchar()) == '\n')
      valid = 0;
    else if (c == EOF)
      valid = 0;
    else {
      s[i] = c;
      ++i;
    }
  }
}
