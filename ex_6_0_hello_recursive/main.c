#include <stdio.h>
#include <stdlib.h>

//const char s = "Hello Recursive World!\n";

char prints( char *s ) {
    if ( s!=0 ) {

    } else {
        putchar(s);
        prints(++s);
    }
}




int main()
{
    prints("Hello world!\n");
    return 0;
}
