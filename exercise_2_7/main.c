/*-----------------------------------------
Name:
Author: Anders Näsman
Compiler: Code::Blocks 16.01

-----------------------------------------*/
#include <stdio.h>

int main()
{
    int a,b, c, min=-2e9,max=+2e9;
    printf("input two numbers:");

    scanf("%d%d%d",&a,&b,&c);

    min=a<b?a:b;
    max=a>b?a:b;

    // if a>b and a>c...
    min=a<b?a<c?a:(b<c?b:c);
    max=a>b?a>c?a:(b>c?b:c);

    printf("min %d max %d \n", min,max);

    return 0;
}
