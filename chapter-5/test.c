#include <stdio.h>

main()
{
    int *a;
    int x = 24;
    int y = 22;
    
    a = &x;	/* a now points to address of x */
    y = *a;	/* y is now 24 */
    *a = 0;	/* x is now 0 */
    
    printf("x: %d, y: %d\n", x, y);
    return 0;
}