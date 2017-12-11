#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <vector>
using std::vector;

template <class T>
class Iterator;

class List : public Term {
public:
  string symbol() const{
	  string _symbol;
	  if(_elements.size()==0)
	  {
		  return "[]";
	  }
		_symbol+="[";
		for(int i=0;i<_elements.size()-1;i++)
		{
			_symbol=_symbol+_elements[i]->value()+", ";
		}
		_symbol=_symbol+_elements[_elements.size()-1]->value()+"]";
		return _symbol;
  }
  string value() const{
	  string _symbol;
	  if(_elements.size()==0)
	  {
		  return "[]";
	  }
		_symbol+="[";
		for(int i=0;i<_elements.size()-1;i++)
		{
			_symbol=_symbol+_elements[i]->value()+", ";
		}
		_symbol=_symbol+_elements[_elements.size()-1]->value()+"]";
		return _symbol;
  }
  bool match(Term & term){
		if(term.assignable())
		{
			return term.match(*this);
		}
		List *ps = dynamic_cast<List *>(&term);
		if (ps){
			if(_elements.size()!= ps->_elements.size())
				return false;
			for(int i=0;i<_elements.size();i++){
				if(!(_elements[i]->match(*(ps->_elements[i]))))
					return false;
			}
		return true;
		}
	return false;
  }
  void assign(Term *term){}
  bool assignable()const{return _assignable;}

public:
  List (): _elements() {}
  List (vector<Term *> const & elements):_elements(elements){}
  Term * head() const{
	 if (_elements.empty())
	{
		throw string("Accessing head in an empty list");
	}
	
		return _elements[0];
  }
  List * tail() {
	  if (_elements.empty())
	{
		throw string("Accessing tail in an empty list");
	}
	  vector<Term *> temp;
	  for(int i=1;i<_elements.size();i++)
	  {
		  temp.push_back(_elements[i]);
	  }
	  List * _tail=new List(temp);
	  return _tail;
  }
  
  bool variable_in_term(Term *term){
	  for(int i=0;i<_elements.size();i++)
	  {
		  if(term==_elements[i])
		  {
			  return true;
		  }
	  }
	  return false;
  }
  int arity(){return _elements.size();}
Term* args(int index){return _elements[index];}
  vector<Term *> _elements;
  Iterator<Term *> *createIterator();

private:
  
  bool _assignable=false;
  

};

#endif