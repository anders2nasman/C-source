#include <stdio.h>
#include <time.h>
#include <math.h>
#include <windows.h>


#define LINES 60
#define ROWS    1024
#define COLUMNS 1024
char mem[ROWS][COLUMNS];


char circle(int r)
{
    int xi,yi;
    double x,y;
    //for (xi=0; xi<2*M_PI; xi+=M_PI/8)
    xi=0; while(xi<2*M_PI)
    {
        //for (yi=0; yi<2*M_PI; yi+=M_PI/8)
        yi=0; while (yi<2*M_PI)
        {
            x = r*cos( xi /COLUMNS );
            y = r*sin( yi /ROWS );
            printf("r=%d, xi=%d, yi=%d, x=%f, y=%f\n",r,xi,yi,x,y);
            yi+=M_PI/8;
        }
        xi+=M_PI/8;
    }

}


int clear()
{
    int i;
    for (i=0; i<LINES; i++)
    {
        putch('\n');
    }
}




int main()
{
    int radius=10;
    int radius2=radius*radius;
    int p;
    int x,y;
    for ( x=-radius; x<=radius; x++)
    {
        for ( y=-radius; y<=radius; y++)
    {
        x=p&0xff00>>8;
        y=p&0x00ff>>0;
        if ( x*y>radius && x*y<radius ) putch('#'))
        elseif ( x*y<radius && x*y<radius ) putch(' '))
        if ( x>radius ) putch('\n'))
    }
    }




    /*
    while (1)
    {
        clear();
        printf("Hello world!\n");
        circle(radius++);
        Sleep(10);
    }
    */
    return 0;
}


/*

circle by #

variable r




*/
