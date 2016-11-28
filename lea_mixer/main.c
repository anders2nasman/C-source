#include <stdio.h>

#define SIZE 1024
#define CHANNELS 8

int main()
{
    printf("Hello world!\n");

    int audio[CHANNELS][SIZE]={10};
    int volume[CHANNELS]={ 2,56,87,31, 70,9,42,23 };
    int i,c,out=0;

    for (i=0,out=0; i<SIZE; i++) {

        for (c=0; c<CHANNELS; c++) {
            out += audio[c][i] * volume[c];
        }
        printf("%d\n",out);

    }




    return 0;
}
