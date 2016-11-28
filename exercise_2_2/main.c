#include <stdio.h>
#include <stdlib.h>


//
int area(int x, int y)
{
    return x*y;
}

int circumference(int x, int y)
{
    return 2*(x+y);
}
double areaf(double x, double y)
{
    return x*y;
}

double circumferencef(double x, double y)
{
    return 2.0*(x+y);
}

#define AREA(x,y) x*y
#define CIRCUMFERENCE(x,y) 2*(x+y)
#define TYPE int double
#define TAG d f

typedef struct
{
    int id;
    char name[12];
    char escape[6];
} typeinfo_t;

typeinfo_t type_table[] =
[
    { 0, "int", "d" },
    { 0, "float", "f" }

];

int main()
{
    int  x,y, a,c= 0;
    printf("area and circumference of rectangle\n input x and y : ");

    scanf("%d %d",&x,&y);

    a=x*y;
    c=2*x+2*y;

    printf("x=%d y=%d a=%d c=%d \n",x,y,a,c);
    printf("x=%d y=%d a=%d c=%d \n",x,y,area(x,y),circumference(x,y));
    return 0;
}
