#include "view.h"

void View::present(const string& text)
{
    cout<<text.data()<<endl; // 161207 anders, added out
}

char View::getchar()
{
  char ch;  // 161207 anders, added input
  // cin>>ch;
  ch=cin.get();
  return ch;
}

pair<string, string> View::getdata()
{
	pair<string, string> input;
	string line;
	getline(cin, line);
	stringstream ss(line);
	ss >> input.first >> input.second;
	return input;
}

string View::getstring()
{
    string s;
    getline(cin,s);
    return(s);
}
