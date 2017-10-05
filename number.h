#ifndef NUMBER_H
#define NUMBER_H

#include <string>
#include "predicate.h"
using namespace std;

class Number :public Predicate {
public:
	Number (int s) {
		_symbol=to_string(s);
		_value=to_string(s);
	}
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