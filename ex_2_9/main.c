#include <stdio.h>

int main(void)
{
   int num=23;

   printf("%d++ ",num++);   printf("%d\n",num);
   printf("++%d ",++num);   printf("%d\n",num);
   printf("%d-- ",num--);   printf("%d\n",num);
   printf("--%d ",--num);   printf("%d\n\n",num);

   num=88;

   printf("%d\n",num=5);
   printf("%d\n",num+=5);
   printf("%d\n",num=+5);
   printf("%d\n",num*=5);
   printf("%d\n",num-=5);
   printf("%d\n",num/=5);
   printf("%d\n",num%=5);

   return 0;
}
