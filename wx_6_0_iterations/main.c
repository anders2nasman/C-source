#include <stdio.h>


unsigned int faculty(int i, unsigned int a) {
    if ( i<= 0 ) {
        return(a);
    } else {
        a = a * --i;
        faculty(i,a);
    }
    // a>=2**32-1;
}

unsigned int fac(int n)
{
    unsigned int result;
    if ( n <= 1 ) {
        return (1);
    } else {
        return( fac(n-1)*n );
    }

}

typedef struct _vector {
    unsigned int a[1000]={0};
    int length=0;
} VECTOR;

VECTOR *fac_a(VECTOR *a, int i, int n)
{
    unsigned int result;
    if ( n <= 1 ) {

        return (1); // according to definition of n!
    } else {
        return( fac(n-1)*n );
    }

}


int main()
{
    int a,n;
    printf("Hello world!\n");

    for (n=0;;n++)
    {
            printf("%u\t%u\n",n,fac(n));
getchar();
    }



    return 0;
}
