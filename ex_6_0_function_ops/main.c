#include <stdio.h>

// print int, no space, no new line
int printint( int a )
{
    printf("%d",a);
    return(a);
}
// print binary expression and result
int printexp( int a, int b, char op, int c )
{
    printf("%d %c %d = %d",a,op,b,c);
    return(a);
}
int add( int a, int b )
{
    printexp(a,b,'+',a+b);
    putchar('\n');
    return a+b;
}
int sub( int a, int b )
{
    printexp(a,b,'-',a-b);
    putchar('\n');
    return a-b;
}
int mul( int a, int b )
{
    printexp(a,b,'*',a*b);
    putchar('\n');
    return a*b;
}
int div( int a, int b )
{
    printexp(a,b,'/',a/b);
    putchar('\n');
    return a/b;
}
int nop( int a, int b )
{
    printexp(a,b,'_',a/b);
    putchar('\n');
    return 0;
}
typedef int (*funptr)(int,int);
funptr add_test = &add;
funptr funtab[] = {
    &nop,   // 0
    &nop,
    &mul,   // '*' & 7
    &add,   // '+' & 7
    &nop,
    &sub,   // '.' & 7
    &nop,
    &div    // '/' & 7
};

int funcall(int a, char op, int b) {
    return funtab[op&7](a,b);
}

typedef struct _bexpr {
    int a;
    char op;
    int b;
} BEXPR;

typedef struct _uexpr {
    char op;
    int a;
} UEXPR;

int funcalls(BEXPR *e) {
    return funtab[e->op&7](e->a,e->b);
}

int main()
{

    int a=5,b=7,c,i,j;
    BEXPR expr[12];

    printf("Claculator\n");
    /*
    printf("add  %02x %02x 0\n",'+','+'&7);
    printf("sub  %02x %02x 1\n",'-','-'&7);
    printf("mul  %02x %02x 2\n",'*','*'&7);
    printf("div  %02x %02x 3\n",'/','/'&7);
    */

    i=0; expr[i].a=5;  expr[i].op='+';  expr[i].b=7;
    i=1; expr[i].a=7;  expr[i].op='-';  expr[i].b=5;
    i=2; expr[i].a=5;  expr[i].op='*';  expr[i].b=7;
    i=3; expr[i].a=12;  expr[i].op='/';  expr[i].b=3;

    for (j=0; j<=i; j++) {
        c=funcalls(&expr[j]);
        printf("%d %c %d = %d \n",expr[j].a,expr[j].op,expr[j].b,c);
    }


    //c = add(a,b);
    printf("v.s.b.\n");
    return 0;
}


/*

Let's start with a basic function which we will be pointing to:
int addInt(int n, int m) {
    return n+m;
}

First thing, lets define a pointer to a function which receives 2 ints and returns and int:
int (*functionPtr)(int,int);

Now we can safely point to our function:
functionPtr = &addInt;

Now that we have a pointer to the function, lets use it:
int sum = (*functionPtr)(2, 3); // sum == 5

Passing the pointer to another function is basically the same:
int add2to3(int (*functionPtr)(int, int)) {
    return (*functionPtr)(2, 3);
}

We can use function pointers in return values as well (try to keep up, it gets messy):
// this is a function called functionFactory which receives parameter n
// and returns a pointer to another function which receives two ints
// and it returns another int
int (*functionFactory(int n))(int, int) {
    printf("Got parameter %d", n);
    int (*functionPtr)(int,int) = &addInt;
    return functionPtr;
}

But it's much nicer to use a typedef:
typedef int (*myFuncDef)(int, int);
// note that the typedef name is indeed myFuncDef

myFuncDef functionFactory(int n) {
    printf("Got parameter %d", n);
    myFuncDef functionPtr = &addInt;
    return functionPtr;
}


*/
