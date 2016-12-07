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
#include <vector>
#include <cmath>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#define INVALID_RATIONAL -1
#define DIVISION_BY_ZERO -89

#define EXPECT( result, expected, message ) \
    cout <<"result="<<result.stringOf()<<" expected= "<<expected.stringOf()<<((result==expected)?" - OK":" - FAILED")<<endl;

using namespace std;

class rational_exception : public std::exception {
    unsigned long time;
    void *instance;
    //string message;
};


class rational {
private:
    int numerator;
    int denominator;
public:
    void simplify();
    //rational() { numerator=0; denominator=1; }
    //rational(int n=0, int d=1) { numerator=n; denominator=d; }
    rational assign(const int &n=0, const int &d=1) { numerator=n; denominator=d; return *this; }
    rational(int n=0, int d=1) { this->assign(n,d); }
    //void assign(int n=0, int d=1) { numerator=n; denominator=d; }
    //rational operator=(rational& r) { this->assign(r.numerator,r.denominator); return *this; }
    //rational operator=(rational r) { this->assign(r->numerator,r->denominator); return this; }
    //rational operator=(const rational& r) { this->numerator=r.numerator; this->denominator=r.denominator; return *this; }
    bool operator==(rational& r) { // const? no we should simplify
            this->simplify();
            r.simplify();
            return this->numerator==r.numerator && this->denominator==r.denominator;
    }

    //rational operator=(rational r){this=r;}
    //throw invalid_argument("rational::rational:: invalid denominator 0");
    float valueOf();
   // rational operator+(int n) { numerator+=n; return this; }
    rational operator++(int dummy) { this->numerator++; return *this; }
    rational operator+(rational n) { rational r=*this; r.numerator+=n.numerator; r.denominator+=n.denominator; return r; }
    rational operator-(rational n) { rational r=*this; r.numerator-=n.numerator; r.denominator-=n.denominator; return r; }
    rational operator*(rational n) { rational r=*this; r.numerator*=n.numerator; r.denominator*=n.denominator; return r; }
    //rational e(rational n) { rational r=*this; r.numerator*=n.numerator; r.denominator*=n.denominator; return r; }
    rational operator/(rational n);
    int greatestCommonDenominator(rational n); // greatest common denominator
    int leastCommonDenominator(rational n); // least common denominator
    void print();
    string stringOf();

};

//-------------------------------------------------------------------- gcd()
int gcd(int m, int n)
{
        int tmp;
        while(m) { tmp = m; m = n % m; n = tmp;
            cout <<"rational::gcd: m = "<<m<<" n="<<n<<endl;
        }
        return n;
}

//-------------------------------------------------------------------- lcm()
int lcm(int m, int n)
{
        return m / gcd(m, n) * n;
}

//-------------------------------------------------------------------- simplify()
void rational::simplify() // to be private
{
    if ( denominator<0 ) { numerator=-numerator; denominator=-denominator; }
    if ( numerator == 0) { denominator=1; }
    if ( denominator == 0) { throw INVALID_RATIONAL; }
    int d = gcd( numerator, denominator );
cout <<"rational::simplify: gcd = "<<d<<endl;
    numerator /= d;
    denominator /= d;
}

int rational::greatestCommonDenominator(rational n) // greatest common denominator
{
    int tmp,tmpm=this->denominator,tmpn=n.denominator;
    while(tmpm) { tmp = tmpm; tmpm = tmpn % tmpm; tmpn = tmp; }
    return tmpn;
}

int rational::leastCommonDenominator(rational n) // least common denominator
{
       // return m / gcd(m, n) * n;
       return this->denominator / this->greatestCommonDenominator(n) * n.denominator;
}


rational rational::operator/(rational n) {
    rational r=*this;
    //if (n.denominator==0) { throw DIVISION_BY_ZERO; };
    //if (r.denominator==0) { throw DIVISION_BY_ZERO; };
    r.numerator *= n.denominator;
    r.denominator *= n.numerator;
    return r;
}


void rational::print() {
    cout << numerator << "/" << denominator;
}

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
        throw DIVISION_BY_ZERO; // typeid(this).name()
    } else {
        return (1.0*numerator / 1.0*denominator);
    }
}


int main()
{
    cout << "Rational Number Class" << endl;

    vector<rational> rats(100);

    //while (1) {
    try {

    rational r,r1(-16,8),r2(3,2),test;
    r  = r1++;

    EXPECT( r1, r, "r assignment = " )

    cout << "r = " << r.stringOf() << endl;
    cout << "r1 = " << r1.stringOf() << endl;

    r1.assign( INT_MAX-1,INT_MAX-1 );
    r1.simplify();
    cout << "simplify r1 = " << r1.stringOf() << endl;

    EXPECT( r1, test.assign(-15,8), "r assignment = " )

    r1.assign(352,64); r1.simplify();
    cout << "simplify r1 = " << r1.stringOf() << endl;

    EXPECT( r1, test.assign(11,2), "r assignment = " )

    rational a(1,3),b(4,5),c(7,15),d(0,1),e(999,0);
    rational f(1,4),g(1,5),h(7,15),i,j(999,0);


    cout << "a = " << a.assign(7,3).stringOf() << endl;

    cout << "a = " << a.stringOf() << endl;
    cout << "b = " << b.stringOf() << endl;

    cout << "lcd(a,b) = " << a.leastCommonDenominator(b) << endl;

    cout << "c = " << c.stringOf() << endl;

    d = ( b + c );

    cout << "d = " << d.stringOf() << endl;

    cout << "lcd(c,d) = " << c.leastCommonDenominator(d) << endl;


    //cout << "e = " << e.stringOf() << endl;
    //cout << "f = " << f.valueOf() << endl;

    h = f - g;
    cout << "h = " << h.stringOf() << " " << h.valueOf() << endl;

    h = f * g;
    cout << "h = " << h.stringOf() << " " << h.valueOf()<< endl;

    h = f / (g + rational(1,100));
    cout << "h = " << h.stringOf() << " " << h.valueOf() << endl;

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
