#ifndef PREDICATE_H
#define PREDICATE_H

using namespace std;

class Predicate {
	public:
	virtual string symbol() const=0;
	virtual string value()const=0;
};

bool match(Predicate &p1,Predicate &p2);

#endif