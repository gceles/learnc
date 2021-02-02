#include <stdio.h>

unsigned long int next = 1;

int rand(void);
void srand(unsigned int seed);

main()
{
  srand(9838);
  printf("%d\n", rand());
  return 0;
}

/* rand: return pseudo-random integer on 0..32767 */
int rand(void)
{
  next = next * 1103515245 + 12345;
  return (unsigned int) (next/65536) % 32768;
}

/* srand: set seed for rand() */
void srand(unsigned int seed)
{
  next = seed;
}
