#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "term.h"
using std::string;

class Variable :public Term{
public:
	Variable (string s):_symbol(s),_value(NULL){}
	string value()const{ 
		if(_value==NULL)
		{
			return _symbol;
		}
		else
		{
			return _value->value();
		}
	}
	string symbol()const{ return _symbol; }
	bool assignable()const{ return !_value; }
	bool match(Term &term){
		if(!this->assignable()&&term.assignable())
		{
			return term.match(*(this));
		}
		if(term.variable_in_term(this))
		{
			return false;
		}
		if(this==&term)
		{
			return true;
		}
		else if(_value==NULL)
		{
			
			_value=&term;
			return true;
		}
		else
		{
			return _value->match(term);
		}
	}
	void assign(Term *term){
		_value=term;
	}
	
	
	bool _assignable=true;
	Term * _value;
	string const _symbol;
private:
	string _name;
	
};

#endif
