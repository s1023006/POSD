#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "predicate.h"
using std::string;

class Variable :public Predicate{
public:
	Variable (string s):_symbol(s){}
	string value()const{ return _value; }
	string symbol()const{ return _symbol; }
	bool assignable()const{ return _assignable; }
	bool match(Predicate &predicate);
	bool _assignable=true;
	void assign(string s){
		_value=s;
		_assignable=false;
	}
	string _value;
	string const _symbol;
private:
	
	
};

#endif
