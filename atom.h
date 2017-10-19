#ifndef ATOM_H
#define ATOM_H

#include <string>
#include "term.h"
#include "number.h"

using std::string;

class Atom :public Term{
public:
	Atom (string s):_symbol(s),_value(s) {}
	Atom (){}
	string symbol()const{ return _symbol; }
	string value()const{ return _value; }
	bool assignable()const{ return _assignable; }
	bool match(Term &term){
		bool ret = _assignable;
		if(term.assignable()){
			term.assign(this);
		}
		return _value == term.value();
	}
	void assign(Term *term){}
	string _symbol;
	string _value;
private:
	
	bool _assignable=false;
  
};

#endif
