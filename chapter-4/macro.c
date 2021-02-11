#include <stdio.h>

#define swap(t, x, y) t tmp; tmp = x; x = y; y = tmp;

main()
{
    int a = 5;
    int b = 6;
    
    swap(int, a, b)
    
    printf("a = %d\nb = %d\n", a, b);
}