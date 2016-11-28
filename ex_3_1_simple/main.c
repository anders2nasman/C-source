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
Gör ett program som läser in flyttal till en flyttalsarray tills man skriver in något som inte är ett tal.
Programmet ska då skriva ut värdena i ordning, baklänges och deras medelvärde.

Tips: kolla upp vad scanf har för returvärde.


*/
