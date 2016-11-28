
#define HELLO_WORD "hello world!\n"
#define HELLO_WORD_CN "你好，世界!\n"

#include "stdio.h"
//#include "stdlib.h"

void main(void) {

    char a_string[] = HELLO_WORD_CN;

    printf( a_string );

    return(0);
}


