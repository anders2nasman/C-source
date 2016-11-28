#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b ;
    unsigned int c;
    printf("Hello world!\n");

    a=3;
    b=a=a++;

    // a and b == 3

    a = a + 1;
    a += 1;
    a++;

    a = -1;
    c = 1;
    if ( (int) a < (int) c ) { puts("a < c"); }

    return 0;
}
