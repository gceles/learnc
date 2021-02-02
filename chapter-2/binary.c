#include <stdio.h>

int binsearch(int x, int v[], int n);

/* test binsearch()  */
main()
{
  int list[] = {3, 4, 9, 10, 12, 14, 24, 30};
  printf("%d\n", binsearch(30, list, 8));
  return 0;
}

/* binsearch: find x in v[] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;

  low = 0;
  high = n - 1;

  while (low <= high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else			/* found match */
      return mid;
  }
  return -1;			/* no match */
}
