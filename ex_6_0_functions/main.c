#include <stdio.h>

int hello(int);
int hello(int a) {
    printf("Hello!\n");
}



int point(int x, int y, int r) {
    if ( sin(x)>0 ) {

    }
    if ( sin(x)>0 ) {

    }

    return 0;
}


int main()
{
    int i=9,j=7; int r=12;
    void p;

    hello();
    (*hello)();
    p = hello;
    (*p)();


    j=point(i,i,r);
    printf("Hello world!\n");
    return 0;
}

