/***
 class: rational
 revision:
   2016-12-02
 throws: invalid_denominator, division_by_zero
***/
#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <typeinfo>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#define INVALID_RATIONAL -1
#define DIVISION_BY_ZERO -89

using namespace std;

class rational_exception : public std::exception {
    unsigned long time;
    void *instance;
};
class rational {
private:
    int numerator;
    int denominator;
public:
    //rational() { numerator=0; denominator=1; }
    rational(int n=0, int d=1) { numerator=n; denominator=d; }
    rational assign(int n=0, int d=1) { numerator=n; denominator=d; return *this; }
    //rational operator=(rational r){this=r;}
    //throw invalid_argument("rational::rational:: invalid denominator 0");
    float valueOf();
   // rational operator+(int n) { numerator+=n; return this; }
    rational operator+(rational n) { rational r=*this; r.numerator+=n.numerator; r.denominator+=n.denominator; return r; }
    rational operator-(rational n) { rational r=*this; r.numerator-=n.numerator; r.denominator-=n.denominator; return r; }
    rational operator*(rational n) { rational r=*this; r.numerator*=n.numerator; r.denominator*=n.denominator; return r; }
    //rational e(rational n) { rational r=*this; r.numerator*=n.numerator; r.denominator*=n.denominator; return r; }
    rational operator/(rational n);
    void print();
    string stringOf();

};


rational rational::operator/(rational n) {
    rational r=*this;
    r.numerator/=n.numerator;
    if (n.denominator==0) { throw DIVISION_BY_ZERO; };
    r.denominator/=n.denominator; return r;
}


void rational::print() { cout << numerator << "/" << denominator; }

//    string stringOf() { itoa(numerator) + "/" + itoa(denominator); }
 //   string stringOf() {
  //          std::string s = std::to_string(numerator); + "/" + std::to_string(denominator); }
string rational::stringOf()
{
    stringstream ss;
    if ( denominator==0 )
    {
        ss << ((numerator>=0)?"plus ":"minus ") << "infinity";
    } else {
        ss << numerator << "/" << denominator;
    }
    string str = ss.str();
    return str;
}

float rational::valueOf()
{
    if ( denominator==0 )
    {
        throw DIVISION_BY_ZERO;
    } else {
        return numerator / denominator;
    }
}


int main()
{
    cout << "Rational Number Class" << endl;

    //while (1) {
    try {

    rational a(1,3),b(4,5),c(7,15),d(0,1),e(999,0);
    rational f(1,0),g(1,0),h(7,15),i,j(999,0);

    cout << "a = " << a.stringOf() << endl;
    cout << "b = " << b.stringOf() << endl;
    cout << "c = " << c.stringOf() << endl;

    d = b + c;

    cout << "d = " << d.stringOf() << endl;
    //cout << "e = " << e.stringOf() << endl;
    //cout << "f = " << f.valueOf() << endl;

    h = f - g;
    cout << "h = " << h.valueOf() << endl;

    } catch (int e) {
        switch (e) {
            case INVALID_RATIONAL : cout << "invalid rational" << endl; break;
            case DIVISION_BY_ZERO : cout << "division by zero" << endl; break;
        }
    }
    //} // while

    //while(int i=0==0){ cout<<"it is an int, or has a value"; }
    return 0;
}
