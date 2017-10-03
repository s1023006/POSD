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