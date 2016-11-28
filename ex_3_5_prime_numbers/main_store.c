#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,c,i=0;
    int d[100];
    //printf(">");
    //scan("%d",&a);
    for (a=1; a<50; a++)
    {
        for (i=1,c=0; i<=a; i++)
        {
            if ( a % i == 0 )
            {
                d[c]=a % i;
                c++;
            }
        }
        if ( c == 2 )
        {
            printf("%d is a prime, divisable with 1 and itself only \n",a);
        }
        else
        {
            printf("%d is a composite number with divisors ",a);
            for (i=0; i<c; i++)
            {
                printf("%d ",d[i]);
            }
            printf("\n");
        }

    }


    return 0;
}
