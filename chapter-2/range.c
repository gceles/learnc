#include <stdio.h>
#include <limits.h>

long getexpo(int base, int exp);

/* determine the ranges of char, short, int, and long variables
   both signed and unsigned */
main()
{
  long temp;

  printf("Range of char:\n");
  temp = getexpo(2, CHAR_BIT);
  printf("%4d - %4d <-- Signed <-- Headers\n", SCHAR_MIN, SCHAR_MAX);
  printf("%4d - %4d <-- Signed <-- Computed\n", 0 - temp / 2, temp / 2 - 1);
  printf("%4d - %4d <-- Unsigned <-- Headers\n", 0, UCHAR_MAX);
  printf("%4d - %4d <-- Unsigned <-- Computed\n", 0, temp - 1);

  printf("Range of short:\n");
  temp = getexpo(2, 16);
  printf("%6d - %6d <-- Signed <-- Headers\n", SHRT_MIN, SHRT_MAX);
  printf("%6d - %6d <-- Signed <-- Computed\n", 0 - temp / 2, temp / 2 - 1);
  printf("%6d - %6d <-- Unsigned <-- Headers\n", 0, USHRT_MAX);
  printf("%6d - %6d <-- Unsigned <-- Computed\n", 0, temp - 1);

  printf("Range of int:\n");
  temp = getexpo(2, 32);
  printf("%6d - %6d <-- Signed <-- Headers\n", INT_MIN, INT_MAX);
  printf("%6d - %6d <-- Signed <-- Computed\n", 0 - temp / 2, temp / 2 - 1);
  printf("%11d - %6u <-- Unsigned <-- Headers\n", 0, UINT_MAX);
  printf("%11d - %6u <-- Unsigned <-- Computed\n", 0, temp - 1);

  printf("Range of long:\n");
  temp = getexpo(2, 64);
  printf("%11ld - %11ld <-- Signed <-- Headers\n", LONG_MIN, LONG_MAX);
  printf("%20d - %11lu <-- Unsigned <-- Headers\n", 0, ULONG_MAX);

  return 0;
}

/* getexpo: raise b to the power n and return the result */
long getexpo(int b, int n)
{
  long result = 1;
  while (n > 0) {
    result *= b;
    --n;
  }
  return result;
}
