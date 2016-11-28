#include <stdio.h>

int main(void)
{
   int num;

   printf("Enter an integer between 1 and 6: ");
   scanf("%d",&num);

   switch (num)
   {
   case 1:
      printf("You entered one!\n");
      break;
   case 2:
      printf("Two!\n");
      break;
   case 3:
      printf("Three!\n");
      break;
   case 6:
      printf("Greater than five!\n");
   case 5:
      printf("Greater than four!\n");
   case 4:
      printf("Greater than three!\n");
      break;
   default:
      printf("Input error!\n");
      break;
   }

   return 0;
}

