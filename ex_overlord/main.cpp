#include <iostream>
#include <vector>

using namespace std;

class CVector
{
public:
    int x,y;
    CVector() : x(0),y(0) {};
    CVector(int,int);
    CVector operator+(CVector);
};

class CVectorVector: public vector<CVector>
{
    public:
        CVectorVector operator,(CVector c) { this->push_back(c); };

};

CVector::CVector(int a, int b)
{
    this->x = a;
    this->y = b;
}

CVector CVector::operator+(CVector v)
{
    CVector temp;
    temp.x = this->x + v.x;
    temp.y = this->y + v.y;
    return temp;
}

int main()
{
    vector<CVector> vector_vector;

    CVector a(3,1);
    CVector b(1,2);
    CVector c;
    CVectorVector d,e;
    c = a + b;
    d.push_back(a);
    e = ( d, a, b );
    cout << c.x << "," << c.y << endl;
    return 0;
}

