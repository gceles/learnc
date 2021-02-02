#include <string.h>

/* shellsort: sort v[] into increasing order */
void shellsort(int v[], int n)
{
  int gap, i, j, temp;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j]>v[j+gap]; j-=gap) {
	temp = v[j];
	v[j] = v[j+gap];
	v[j+gap] = temp;
      }
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
