#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a,c,i,j=0;
    char s[500],t[200];
    // do {
    //printf(">");
    //scan("%u",&a);
    // } while (a<1);
    for (a=1; a<65535; a++)
    {
        //printf("divisors ");
        sprintf(s,"%c",'\0'); // clear temporary string
        for (i=1,c=0; i<=a; i++)
        {
            if ( (a % i) == 0 )
            {
                c++; // count divisors
                //printf("%d ",i);
                sprintf(t,"%u ",i);
                strcat(s,t);
            }
        }
        //printf("\t\t");
        if ( c == 2 )  // should check that it is 1 and itself
        {
            printf("prime[%u]=%u\n",j++,a);
            //printf("%d is a prime, divisable with 1 and itself only \n",a);
            //printf("\tdivisors %s\n",s);
        }
        else if ( c == 1 )
        {
            //printf("%d is no longer a prime \n",a);
           // printf("\tdivisors %s\n",s);
        }
        else
        {
            //printf("%d is not a prime number \n",a);
            //printf("\tdivisors %s\n",s);
        }

    }


    return 0;
}
