#include <stdio.h>

int main(void)
{
    // declarations first
    int side1, side2;
    printf("enter two integers: ");
    scanf("%d%d",&side1,&side2);

    printf("area %d, circumference %d \n", side1*side2, 2*(side1+side2) );
    return 0;
}
