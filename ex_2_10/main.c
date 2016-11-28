#include <stdio.h>
#include <math.h>
#include <windows.h>

int main(void)
{
   float num1=8.1;
   float num2=7.9;
   double result;

   printf("%.4f + %.4f = %.4f\n",num1,num2,num1+num2);
   printf("%.4f - %.4f = %.4f\n",num1,num2,num1-num2);
   printf("%.4f * %.4f = %.4f\n",num1,num2,num1*num2);
   printf("%.4f / %.4f = %.4f\n",num1,num2,num1/num2);
   printf("%.4f %% %.4f = %.4f\n",num1,num2,fmod(num1,num2));
   printf("%.4f == %.4f = %d\n",num1,num2,num1==num2);
   printf("%.4f != %.4f = %d\n",num1,num2,num1!=num2);
   printf("%.4f < %.4f = %d\n",num1,num2,num1<num2);
   printf("%.4f > %.4f = %d\n",num1,num2,num1>num2);

   result=fmod(num1+2*num2/4-(num1+1),4);
   puts("sleep..."); Sleep(1*1e3);

   printf("\nThe result is %.4f", result);

   return 0;
}

