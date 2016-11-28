#include <stdio.h>

int main(void)
{
   int a,b,c;

   a=1;
   b=3;

   a=3*a+b*2;     //What is the value of c at this line? 7417784 unknown
   b=a+3+1;

   c=a+b;         //What is the value of c after this line? 22

   a=b-a;
   b=a-c;

   c=a+b;

   printf("%d",c); //What value does c get if a starts out equaling 2? (do not edit the program) -20

   return 0;
}


