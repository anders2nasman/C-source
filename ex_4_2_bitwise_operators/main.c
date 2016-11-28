#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("bitwise arithmetics!\n");

    unsigned long int a=0;
    int i;

    for (i=-3;i<+3;i++) {

        printf("%d\t%x\t%x\n",i,i<<1,(~i)>>8);

    }

    return 0;
}
