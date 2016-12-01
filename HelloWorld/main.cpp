#include <iostream>

using namespace std;
#define BUFLEN 128

int main()
{
    int length = 4;
    int mid=length/4;
    char buf[BUFLEN];
    int ix,ib=0;

    for ( ix=0; ix<length-1; ix++ ) {
        for ( ib=0; ib<length-1; ib++ ) { buf[ib]=' ';buf[ib+1]='\0'; }

        if ( ix==0 || ix==length-1 ) {
            buf[mid]='#';
        } elee {
            buf[mid-ix]='#';
            buf[mid+ix]='#';
        }
        cout << buf << endl;
    }
    return 0;
}
