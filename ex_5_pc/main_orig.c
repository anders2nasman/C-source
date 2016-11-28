#include <stdio.h>
#define LENGTH 39
int main(void)
{
    char message[] = { 254, 200, 206, 194, 195, 201, 141, 222, 217, 204, 202, 200, 141, 193, 204, 216,
                       195, 206, 197, 141, 206, 194, 201, 200, 141, 196, 222, 141, 156, 202, 225, 229,
                       200, 244, 194, 218, 147, 228, 0 };

    char *c=message;
    int i=0;
    unsigned int a=0;
    unsigned char cc,pc;
    int freq[256]={0};

    for ( i=0; i<LENGTH; i++ ) {
                a=(unsigned int)message[i]&0xff;
                freq[a]=freq[a]+1;
                cc = message[i];
                pc =  (message[i]>>0)^0xa5;
               printf( "%2d %02x %02x %c \n", i, cc, pc, pc );
    }

    for ( i=0; i<256; i++ ) {
               printf( "%2d %02x %d \n", i, freq[i], freq[i] );
    }

    /*
    while ( c!=0 )

        printf( "%c", *c & 0x7f );
        c++;
    }
    */

    return 0;
}
