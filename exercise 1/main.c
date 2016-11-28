#include <stdio.h>


#define NUMBER 16.0
#define LANG CN


int main_cn();

int main(void)
{
    puts("Hello world!\n");
    {
        int i;
        int j;
        i=NUMBER;
        i+=2000;
        i = j;
        i = j;
        j = i = 5;

        if ( i< 2000) { }

        i = i & 0xff ^ 0xaa << 16   | i & 0xff << 8 ^ 0x55 | i & 0xff;

        //main_cn(i);
        printf(">");
        scanf("%d", &i);
        printf("read %d", i);
    }
    return(0);
}
