#include <stdio.h>
#include <stdlib.h>


char clear_text1[] = "This is the correct solution";
char clear_text2[] = "The launch code is H&kN08jGB";
char key1[] =        "f07dd67c8092699d67c80920e4f2";
char key2[] =        "f07dd67c8092699d67c80920e4f2"; // will be generated
unsigned char enc1[]="0000000000000000000000000000";
unsigned char enc2[]="0000000000000000000000000000";
unsigned char keycode=0xa5;

int main()
{
    int i=0;
    unsigned b=0;
    printf("Hello world!\n");

    for ( i=0; i<sizeof(clear_text1); i++ ) {
        //enc1[i] = clear_text1[i] ^ clear_text2[i] ^ key1[1];
        enc1[i] = clear_text1[i] ^ clear_text2[i] ^ keycode;
    }
    for ( i=0; i<sizeof(clear_text1); i++ ) {
            printf("%02x ",enc1[i]);
    }
    printf(" <-- cipher text\n");
    for ( i=0; 0 && i<sizeof(clear_text1); i++ ) {
            printf("%02x ",key1[i]);
    }
    printf("%02x <-- key \n",keycode);
    for ( i=0; i<sizeof(clear_text1); i++ ) {
            printf("%02x ",clear_text1[i]);
    }
    printf("\n");
    for ( i=0; i<sizeof(clear_text1); i++ ) {
            printf("%c ",clear_text1[i]);
    }
    printf(" <-- clear text 1\n");
    for ( i=0; i<sizeof(clear_text1); i++ ) {
            printf("%02x ",clear_text2[i]);
    }
    printf("\n");
    for ( i=0; i<sizeof(clear_text1); i++ ) {
            printf("%c ",clear_text2[i]);
    }
    printf(" <-- clear text 2\n");
    return 0;
}


/*

#include <stdio.h>
#define LENGTH 39
int main(void)
{
    char message[] = { 254, 200, 206, 194, 195, 201, 141, 222, 217, 204, 202, 200, 141, 193, 204, 216,
                       195, 206, 197, 141, 206, 194, 201, 200, 141, 196, 222, 141, 156, 202, 225, 229,
                       200, 244, 194, 218, 147, 228, 0 };


                       */
