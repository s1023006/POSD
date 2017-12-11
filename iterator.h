#ifndef ITERATOR_H
#define ITERATOR_H

#include "term.h"
using namespace std;

class Term;

template <class T>
class Iterator
{
	public:
	virtual Term* currentTerm()const=0;
	virtual bool isDone()const=0;
	virtual Term* currentItem()const=0;
	virtual void next()=0;
};

template <class T>
class usualIterator:public Iterator<T>
{
	public:
	friend class Term;
	void next(){}
	Term* currentTerm()const
	{
		return _t;
	}
	bool isDone()const
	{
		return true;
	}
	Term* currentItem()const{return nullptr;}
	private:
	
	usualIterator(T t):_t(t){}
	T _t;
	
};
/*
template <class T>
class StructIterator:public Iterator<T>
{
	public:
	friend class Struct;
	
	Term* currentTerm()const
	{
		return _s;
	}
	bool isDone()const
	{
		return _index>= _s->arity();
	}
	Term* currentItem()const
	{
		return _s->args(_index);
	}
	void next(){_index++;}
	
	private:
	StructIterator(Struct *s):_index(0),_s(s){}
	int _index;
	Struct *_s;
	
};
*/



#endif