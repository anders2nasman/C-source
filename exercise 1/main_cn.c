
#define HELLO_WORLD_EN "Hello world!\n"
#define HELLO_WORLD HELLO_WORLD_EN

#define HELLO_WORLD_SE "Hej världen!\n"
#define HELLO_WORLD_CN "你好，世界!\n"
#define HELLO_WORLD_AR "مرحبا بالعالم\n"

#ifdef LANG
#define HELLO_WORLD HELLO_WORLD_(LANG)
#elseif
#define HELLO_WORLD HELLO_WORLD_EN
#endif // LANG

#define HELLO_YEAR "%4d - %s"
#define THIS_YEAR 2016

#include <stdio.h>
//#include "stdlib.h"

int main_cn(int a_year)
{
    //int a_year = THIS_YEAR;
    char a_string[] = HELLO_WORLD;

    printf( HELLO_YEAR, a_year, a_string );

    return(0);
}



