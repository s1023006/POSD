#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "predicate.h"
using std::string;

class Atom :public Predicate{
public:
	Atom (string s):_symbol(s),_value(s) {}
	string symbol()const{ return _symbol; }
	string value()const{ return _value; }
	bool assignable()const{ return _assignable; }
	bool match(Predicate &predicate){
		bool ret = _assignable;
		if(predicate.assignable()){
			predicate.assign(_value);
		}
		return _value == predicate.value();
	}
	void assign(string s){
		_value=s;
		_assignable=false;
	}
private:
	string _symbol;
	string _value;
	bool _assignable=false;
  
};

#endif
