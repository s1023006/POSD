#include "number.h"
#include "atom.h"
#include "variable.h"
#include "predicate.h"
#include <iostream>

using std::string;

bool Number::match(Predicate &predicate){
	bool ret = _assignable;
	if(predicate.assignable()){
		predicate.assign(_value);
	}
	return _value == predicate.value();
}

/*bool match(Number n1,Number n2){
	return n1.value() == n2.value();
}

bool match(Number number,Atom atom){
	return number.value() == atom.symbol();
}

bool match(Number number,Variable &variable){
	bool ret = variable.assignable();
		if(variable.assignable()){
		  variable._value = number.value() ;
		  variable._assignable = false;
		}
	return number.value() == variable.value();
}*/

bool Atom::match(Predicate &predicate){
	bool ret = _assignable;
	if(predicate.assignable()){
		predicate.assign(_value);
	}
	return _value == predicate.value();
}

/*bool match(Atom atom,Number number){
	return atom.symbol() == number.value();
}

bool match(Atom a1,Atom a2){
	return a1.symbol() == a2.symbol();
}

bool match(Atom atom,Variable &variable){
	bool ret = variable.assignable();
		if(variable.assignable()){
		  variable._value = atom.symbol() ;
		  variable._assignable = false;
		}
	return atom.symbol() == variable.value();
}*/

bool Variable::match(Predicate &predicate){
	bool ret = _assignable;
		if(_assignable){
		  _value = predicate.value();
		  _assignable = false;
		}
		else if(predicate.assignable()){
		  predicate._value = _value;
		  predicate._assignable = false;
		}
		return _value == predicate.value();
}

/*bool match(Variable &variable,Atom atom){
	bool ret = variable.assignable();
		if(variable.assignable()){
		  variable._value = atom.symbol() ;
		  variable._assignable = false;
		}
		return variable.value() == atom.symbol();
}

bool match(Variable &variable,Number number){
	bool ret = variable.assignable();
		if(variable.assignable()){
		  variable._value = number.value() ;
		  variable._assignable = false;
		}
    return variable.value() == number.value();
}*/
