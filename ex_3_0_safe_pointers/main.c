#include <stdio.h>

#include <stdint.h>

#define pointer(x,px) x,((*px)=x)
#define dereference(x) (*x)
#define range(x,y) (y-x)

int main()
{

    int a, *pa=&a, **ppa=&pa;
    int b, *pb=&b, **ppb=&pb;
    //int pointer(pb) = &b;
    int pointer(c,pc);
    int pointer(c[5],pc);
    int pointer(d[range(3,8)],pd);

    a = 9;
    *pa =0x88;

    b = a;
    pb = (int *)&b;
    c = *pa;
    //c = dereference(b);


    printf("c = %d\n", c);
    printf("ppa %p pointer %p address %p data %d\n", &ppa, &pa, pa, **ppa);
    //printf("address %p data %d\n", &pb, pb, dereference(b);
    return 0;
}
