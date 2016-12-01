#include <iostream>

using namespace std;

int main()
{
    int a;
    int &r=a; // referensen till a, has to be defined, stuck to a

    a=9;
    r=7;

    //cout << "Hello world!" << endl;
    return a;
}
