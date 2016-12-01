#include <iostream>
#include <iomanip>

using namespace std;

#define PREC 4
int main()
{
    float len,wid=0.0;

    cout << "give length and width : ";
    cin >> len >> wid;

    //cout << setiosflags(ios::fixed) << setprecision(PREC);
    cout << fixed << setprecision(PREC);
    cout << " area " << setw(6) << setprecision(PREC) << (len*wid)
         << " circumference "  << setw(6) << (2*len+2*wid) << endl;
    return 0;
}
