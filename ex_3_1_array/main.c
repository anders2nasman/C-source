#include <stdio.h>
#include <stdlib.h>


#define LENGTH 16

int main()
{
    int aa=45;
    asm {
        LEA
    }
    const int i=16;

    int a[LENGTH] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 }; // 0
    int b[LENGTH] = { 0 }; // all 0
    char c[LENGTH] = { 'a', 'b', 'c', 'd' ,'e','f' }; // remaining 0

    x = a[7]; // base address + index * sizeof(int), sizeof(a)

    // LEA
    // size = sizeof(a) / sizeof(a[0]

    printf("Hello world!\n");
    return 0;
}
