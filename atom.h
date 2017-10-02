#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "predicate.h"
using std::string;

class Atom :public Predicate{
public:
  Atom (string s):_symbol(s),_value(s) {}
  string symbol()const{
	  return _symbol;
  }
  string value()const{
	  return _value;
  }
private:
  string _symbol;
  string _value;
  
};

#endif
