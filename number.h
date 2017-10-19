#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include <iostream>
#include "term.h"
using namespace std;

class Number :public Term {
public:
	Number (double s) {
		_symbol=to_string(s);
		for(int i=_symbol.size()-1;i>=0;i--)
		{
			if(_symbol[i]=='0')
			{
				_symbol.erase(_symbol.begin()+i);
			}
			else if(_symbol[i]=='.')
			{
				_symbol.erase(_symbol.begin()+i);
				break;
			}
			else
			{
				break;
			}
		}
		_value=_symbol;
	}
	Number (int s) {
		_symbol=to_string(s);
		_value=to_string(s);
	}
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
	
private:
	string _symbol;
	string _value;
	bool _assignable=false;
};

#endif