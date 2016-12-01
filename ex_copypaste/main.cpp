#include <iostream>
//#include <vector>
#include <string>
//#include "boost/tuple/tuple.hpp"
//#include "boost/tuple/tuple"
#include <utility>      // std::pair, std::make_pair

using namespace std;
//using boost::tuple;

//typedef vector< tuple<string,string> > change_list;

int main()
{
    string one("I walked down the canyon with the moving mountain bikers.");
    string two("The bikers passed by me too close for comfort.");
    string three("I went hiking instead.");

    change_list change;
    change.push_back( tuple<int, string>("walked","moved") );
    change.push_back( tuple<int, string>("moving ","") );
    change.push_back( tuple<int, string>("The bikers","The mountain bikers") );
    change.push_back( tuple<int, string>("I went", "So I went") );

    string result;

    //one.copy( result, one.size() );
    result.append( one );
    result.append( " " );
    result.append( two );
    result.append( " " );
    result.append( three );

/*
    struct _CHANGE {
        string from;
        string to;
    } change;
    change changes[];
        { "walked","moved",
            "moving ","",
            "The bikers","The mountain bikers"};
            "I went", "So I went"

    changes[0] = { "walked","moved", };
    changes[0] =  "moving ","",
            "The bikers","The mountain bikers"};
    for (int ix=0; ix<sizeof(changes); ix++) {
        result.replace( result.find(changes[ix].from), changes[ix].size(), changes[ix].to );
    }
*/
    list< tuple<string,string> > change;

    for (change::const_iterator i = change.begin(); i != change.end(); ++i) {
        result.replace( result.find(i->get<0>()), i->get<0>().size(), i->get<1>() );
    }
    cout << result << endl;

    result.replace( result.find("walked"), 6, "moved" );
    result.replace( result.find("moving "), 7,"" );
    result.replace( result.find("The bikers"), 10, "The mountain bikers" );
    result.replace( result.find("I went"), 6, "So I went" );

    //"I moved down the canyon with the mountain bikers. The mountain bikers passed by me too close for comfort. So I went hiking instead.
    cout << result << endl;
    return 0;
}

/*

// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

int main () {
  std::pair <std::string,double> product1;                     // default constructor
  std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  std::pair <std::string,double> product3 (product2);          // copy constructor

  product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
  return 0;
}


*/
