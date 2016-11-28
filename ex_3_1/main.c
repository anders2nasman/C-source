#include <stdio.h>

#define LENGTH 1
#define RANGECHECK(length,index) (index>=0&&index<LENGTH)

int function sort(double *x, unsigned int len)
{
    int ix,rx,tmp=0;
    double *pt,*pr = x;
    for (ix=0;ix<len;ix++ )
    {
        tmp = *
        for (rx=ix;rx<len; rx++)
        {

        }
    }
}
int function sort(double *x, unsigned int len)
{
  for each (unsorted) partition

  randomly select pivot, swap with first element

  storeIndex = pivotIndex + 1

  for i = pivotIndex + 1 to rightmostIndex

    if element[i] < element[pivot]

      swap(i, storeIndex); storeIndex++

  swap(pivot, storeIndex - 1)
}

int main()
{
    unsigned i, index = 0;
    float x=0;
    double avg=0, avg2=0, a[LENGTH] = { 0.0 }; // clear all
    int valid=0;
    double *px = a;
    printf("enter max %d real numbers (end with '.') :",LENGTH);
    do
    {
        valid = scanf( "%ld", &x ) > 0;
        if ( valid )
        {
            a[index++] = x; // only place to assign and
            avg += x;       // sum for average
        }
    }
    while ( valid && index<LENGTH );

    // sort( a );
    // well, range check should not be a problem in for loops
    for ( i=0; i<index && RANGECHECK(LENGTH,i); i++ )
    {
        printf("a[%d] = %f\n",i,a[i]);

    }
    for ( avg2=0, i=index-1; i>=0 && RANGECHECK(LENGTH,i); i-- )
    {
        printf("a[%d] = %f\n",i,a[i]);
        avg2 += a[i];
    }
    if ( i>0 )
    {
        printf("on-the-fly average = %f \n", avg / index);
        printf("average = %f \n", avg2 / index);
    }
    else
    {
        printf("you were supposed to input some real values...");
    }
    return 0;
}


/*
Gör ett program som läser in flyttal till en flyttalsarray tills man skriver in något som inte är ett tal.
Programmet ska då skriva ut värdena i ordning, baklänges och deras medelvärde.

Tips: kolla upp vad scanf har för returvärde.


*/
