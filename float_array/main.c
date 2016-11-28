#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
float a[SIZE]={0.0, 1, 2,3,4,5,6 };
float b[SIZE]={2,4,8,16,32,64,128};
float c[SIZE]={0.0};

int add( float *a, float *b, float *c, int len) {
    int i;
    for (i=0; i<len; i++) {
        c[i] = a[i]+b[i];
    }
}


int main()
{
     int i,j,len=SIZE;
    printf("add float array!\n");
    for (j=1; j<len; j++) {
      add(a,b,c,j);
      for (i=0; i<len; i++) {
        printf( "%0.3f ", c[i]);
      }
        printf("\n");
    }
    return 0;
}


/*
Skriv ett program med en funktion som klarar av att addera två godtyckligt långa (men lika långa) float-arrayer elementvis till en tredje array.

Arrayerna ska inte läsas in från användaren.
Använd funktionen i programmet för att visa att den kan addera arraypar av olika längder.
*/
