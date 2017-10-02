#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "predicate.h"
using std::string;

class Variable :public Predicate{
public:
	Variable(string s):_symbol(s){}
	string value()const{ return _value; }
	string symbol()const{ return _symbol; }
	bool assignable(){ return _assignable; }
	bool _assignable = true;
	string _value;
	string const _symbol;
private:
	
	
};

#endif
