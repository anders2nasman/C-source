#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    int len,mid,ix=0;

    cout << "diamond, give length : ";
    cin >> len;
    mid=len/2;

    for (ix=0; ix<2*len-1; ix++) {
        if ( ix>0 || ix<2*len-1) {
          cout << setw(mid-(ix>len?len-ix:ix)) << ' ' << '#';
        }
        cout << setw(mid+(ix>len?len-ix:ix)) << ' '<< '#'  << endl;
    }

    return 0;
}
