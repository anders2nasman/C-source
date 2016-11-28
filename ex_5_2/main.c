#include <stdio.h>
// nybble bits and width
#define NB 4
#define NW 0xf


unsigned char find_a_nybble(unsigned long long src, char nyb)
{
    unsigned char a=0;
    int i=0;
    do {
      a = src & 0xf;
      if ( a == nyb ) { return a; }
      src =  src >> 4;
      i++;
    } while ( i<sizeof(src)*2 );

    return '-';
}




int main(void)
{
   const int Num1=0x0123;
   const int Num2=0x4567;
   const int Num3=0x89ab;
   const int Num4=0xcdef;

    int  result, pos,nyb;
    unsigned long long int Num, tmp;
    // START
    result = 0; tmp=0;
    // 0x0123 0x4567  0x89ab 0xcdef;
    Num = (unsigned long int)Num1<<48 | (unsigned long int)Num2<<32 | (unsigned long int)Num3<<16 | (unsigned long int)Num4;
    pos=7; nyb=3;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // c
    pos=6; nyb=5;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // a
    pos=5; nyb=0;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // f
    pos=4; nyb=1;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // e
    pos=3; nyb=0;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // f
    pos=2; nyb=15; tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // 0
    pos=1; nyb=15; tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // 0
    pos=0; nyb=2;  tmp |= ((Num >> nyb*NB) & NW) << pos*NB; // d
    result=tmp;

    printf("%c",find_a_nybble(Num,0xc));
    printf("%c",find_a_nybble(Num,0xa));
    printf("%c",find_a_nybble(Num,0xf));
    printf("%c",find_a_nybble(Num,0xe));
    printf("%c",find_a_nybble(Num,0xf));
    printf("%c",find_a_nybble(Num,0x0));
    printf("%c",find_a_nybble(Num,0x0));
    printf("%c",find_a_nybble(Num,0xd));
    printf("\n");
   // END

   printf("%x\n",result);

   return 0;
}
/*
Gör så att programmet skriver ut cafef00d.

Använd dig av bitarna i de konstanter som finns i programmet.
Se dem som värden från periferienheter i t.ex. en mikrokontroller,
ändringar i konstanterna ska ge upphov till motsvarande ändringar i resultatet.

Endast tilldelningar och bitvisa operatorer är tillåtna.
Koden utanför START och END får ej röras.
Det är tillåtet att deklarera fler variabler.

*/

