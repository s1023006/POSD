#ifndef NUMBER_H
#define NUMBER_H

#include "atom.h"

string Atom::value(){
	return _value;
}

string Atom::symbol(){
	return _symbol;
}

bool Atom::match(string s){
	return _value == s;
}

bool Atom::match(Atom a){
	return _value == a._value;
}

#endif