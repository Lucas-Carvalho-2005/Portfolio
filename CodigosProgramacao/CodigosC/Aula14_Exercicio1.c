#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    printf("%d", y);
    --x;
    (*p) = x;

    printf("\nX = %d \nY = %d \n*p = %d\n", x, y, *p);
}
