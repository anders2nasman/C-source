#include <stdio.h>
#include <stdlib.h>

int main()
{

    typedef struct _CAPACITOR
    {
        char typecode[32];	// artikelnummer
        float capacitance;	// kapacitansen i farad
        int maxvoltage;	// maxspänning i volt
        char* description;	// beskrivning av komponenten
    } CAPACITOR;

    CAPACITOR capacitor[12] = { "C123N123",10e-6, 12, "tantal" };
    CAPACITOR cap;

    int count=1; // keep first item
    int result=0, i=0; //
    char c;
    while ( count<3 )
    {
        result=0;
        do
        {
            // perl -ne '/^\s*([^\,]{1,32})\s*,\s*(\d+\.?\d*)\s*,\s*(\d+)\s*\,\s*(.*)/ and (print "$1 $2 $3 $4\n")'
            cap.description=malloc(255*sizeof(char));
            printf("art.no(c), cap(f), voltage(i), desc(c) : ");
            result = scanf("%[^,],%f,%d,%[^\n]s",
                           &cap.typecode,&cap.capacitance,
                           &cap.maxvoltage,cap.description);
            getchar();

            if (result>=4)
            {
                capacitor[count++] = cap;
            }
            else
            {
                printf("invalid input\n");
            }
        }
        while ( !result );

    }

    for (i=0; i<count; i++)
    {
        printf("item %d\t'%s'\t%f F\t%d V\t'%s'\tprice %f\n",i,
               capacitor[i].typecode,capacitor[i].capacitance,
               capacitor[i].maxvoltage,capacitor[i].description,
               1/5*capacitor[i].capacitance*capacitor[i].maxvoltage);
               free(capacitor[i].description);
    }


    return 0;
}


/*


Skriv ett program som matar in data till, och sedan skriver ut informationen i, två statiskt allokerade poster av typen capacitor, som ska ha nedanstående fält:

typecode (char[32])	// artikelnummer
capacitance (float)	// kapacitansen i farad
maxvoltage (int)	// maxspänning i volt
description (char*)	// beskrivning av komponenten

Utskrift ska ske efter inmatning av båda posterna.
Description ska kunna innehålla mellanslag.


*/
