#include <stdio.h>

#define LENGTH 16
int main()
{
    unsigned i, index = 0;
    float x=0;
    float avg=0, avg2=0, a[LENGTH] = { 0.0 }; // clear all
    int valid=0;
    float *px = &a;
    printf("enter real numbers (end with /) :");
    do
    {
        //valid = scanf( "%g", &x ) > 0;
        valid = scanf( "%g", px ) > 0;
        if ( valid )
        {
            //a[index++] = x;
            index += valid; px++;
            //avg = ( avg + x ) / ((index>1)?2:1);
            //avg = ( avg + x ) / 2; // on the fly average
            avg += x;
        }
    }
    while ( valid && index<LENGTH );

    // sort( a );
    for ( i=0; i<index && i<LENGTH; i++ ) {
         printf("a[%d] = %f\n",i,a[i]);

    }
    for ( avg2=0, i=index-1; i>=0 && i<LENGTH; i-- )
    {
        printf("a[%d] = %f\n",i,a[i]);
        avg2 += a[i];
    }
    printf("average = %f \n", avg / index); // on the fly average
    printf("average = %f \n", avg2 / index);

    return 0;
}


/*
Gör ett program som läser in flyttal till en flyttalsarray tills man skriver in något som inte är ett tal.
Programmet ska då skriva ut värdena i ordning, baklänges och deras medelvärde.

Tips: kolla upp vad scanf har för returvärde.


*/
