#include <stdio.h>

int main()
{

    void *pv;

    typedef struct _S {
        char a[12];
        int b;
    } S;
    S s1 = { "abcdef", 6 };
    S s2 = { "asdfklf", 7 };

    S *ps1 = &s1;
    S *ps2 = &s2;
    S *ps3 = &s1;

    pv = ps1;
    ps2 = pv;
    ps3 = ps1;


    printf("sizeof s1=%d, ps2=%d, pv=%d\n", sizeof(s1),sizeof(ps2),sizeof(pv));
    return 0;
}



/*

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct article
{
   char name[16];
   int itemcode;
   int inventory;
   float price;
};

typedef struct
{
   char name[16];
   float mass;
   float charge;
   float spin;
} particle;

int main(void)
{
   struct article article1;
   struct article article2={"Spam",43134419,120,1.99};

   particle particle1;
   particle *p;
   particle particles[2];

   strncpy(article1.name,"Corned beef",12);
   article1.itemcode=32773101;
   article1.inventory=249;
   article1.price=2.29;

   strncpy(particle1.name,"Muon",5);
   particle1.mass=105.7;
   particle1.charge=-1.0;
   particle1.spin=1.0/2.0;

   p=malloc(sizeof(particle));
   strncpy(p->name,"Photon",7);
   p->mass=0.0;
   p->charge=0.0;
   p->spin=1.0;

   particles[0]=particle1;
   particles[1]=*p;

   return 0;
}



*/
