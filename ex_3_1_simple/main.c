#include <stdio.h>

#define LENGTH 1
int main()
{
    float x[LENGTH]; // list of one

    printf("enter max %d real numbers (end with '.') :",LENGTH);
    if ( scanf("%f",&x[0]) >0 ) {;
        printf("forwards  %f \n",x[0]);
        printf("backwards %f \n",x[0]);
        printf("average   %f \n",x[0]/LENGTH);
    } else {
        printf("no values\n");
    }

    return 0;
}


/*
G�r ett program som l�ser in flyttal till en flyttalsarray tills man skriver in n�got som inte �r ett tal.
Programmet ska d� skriva ut v�rdena i ordning, bakl�nges och deras medelv�rde.

Tips: kolla upp vad scanf har f�r returv�rde.


*/
