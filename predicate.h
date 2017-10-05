#ifndef PREDICATE_H
#define PREDICATE_H

using namespace std;

class Predicate {
	public:
	virtual string symbol() const=0;
	virtual string value()const=0;
	virtual bool assignable()const=0;
	virtual bool match(Predicate &p2)=0;
	virtual void assign(string s)=0;
	bool _assignable;
	string _value;
	string const _symbol;
};



#endif