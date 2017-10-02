#ifndef ATOM_H
#define ATOM_H

#include <string>

using std::string;

class Atom {
public:

	Atom (string s,string v) {_symbol=s;_value=v;}
  
	Atom (string s) {
	if(s[0] >= 65 && s[0] <= 90)
		_symbol=s;
	else
		_value=s;
	}
	
  string _symbol,_value;
  string value();
  string symbol();
  bool match(Atom a);
  bool match(string s);
};

#endif
