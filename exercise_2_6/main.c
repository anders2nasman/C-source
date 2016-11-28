

#include <stdio.h>

int main(void)
{
    int num1,num2,div1;
    double num3, num4,div2;

    while (1)
    {
        printf("Enter two integers: ");
        scanf("%d%d",&num1,&num2);

        if (num1==num2)
        {
            printf("The two numbers are equal");
        }
        else
        {
            printf("The two numbers are are not equal");
            printf("\nThe number %d is largest", num1>num2?num1:num2 );
        }

        printf("\nThe division is %d", num1/num2 );
        //printf("\nThe remainder is %d", num1\num2 );
        printf("\nThe modulo is %d", num1%num2 );
        div1=num1/num2;
        num3=(float)1.0*num2;
        num4=(float)1.0*num3;
        div2=num3/num4;
        printf("\nFloat division %f. The remainder is %f \n", div2, (double)(div2)- (int)(div1) );
    }
    return 0;
}

//Utöka programmet med att skriva ut vilket tal som är störst om talen ej är lika.

