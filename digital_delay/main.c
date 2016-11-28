#include <stdio.h>

#define SIZE 8092
#define TAPS 8

int input(int ch,int *x);
int output(int ch, int x);

int buffer[SIZE];
int *write_pointer=&buffer;
int *read_pointer[TAPS]= {&buffer}; // init all pointers to base
int volume[TAPS]= {0};

int modulate_volume(int volume[]) { }
int modulate_delay(int *read_pointer[]) { }
int delay(int *read_pointer[]) { }

// mix channels to output
int mix(int *read_pointer[], int volume[])
{
    int i,c,out=0;

    for (c=-1; c<TAPS; c++) // right, assume that write ptr is -1
    {
        i= read_pointer[c];
        out += buffer[i] * volume[c];
    }
    printf("%d\n",out);

}

int main(void)
{
    printf("digital delay!\n");
    while ( )
    delay( read_pointer );
    mix( read_pointer, volume);
    return 0;
}
