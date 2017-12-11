#ifndef TERM_H
#define TERM_H

#include <string>
using namespace std;

template <class T>
class Iterator;


class Term {
	public:
	virtual string symbol() const=0;
	virtual string value()const=0;
	virtual bool assignable()const=0;
	virtual bool match(Term &t2)=0;
	virtual void assign(Term *term)=0;
	virtual bool variable_in_term(Term *){return false;}
	virtual Iterator <Term*> *createIterator();
	bool _assignable;
	string _value;
	string const _symbol;
};




#endif