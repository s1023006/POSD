#ifndef STRUCT_H
#define STRUCT_H

#include <vector>
#include <string>
#include "term.h"
#include "atom.h"
#include<iostream>
//#include "iterator.h"

using std::string;
class Struct :public Term{
	public:
	Atom _name;
	std::vector<Term *> _arg;
	int _argsize;
	bool _assignable=false;
	
	Term* args(int i){return _arg[i];}
	Atom name(){return _name;}
	Struct(Atom atom, std::vector<Term *> v): _arg(v){
		_name._symbol=atom.symbol();
		_name._value=atom.symbol();
		//_arg.assign(v.begin(),v.end());
	}
	int arity(){
		return _arg.size();
	}
	string symbol()const{
		string _symbol;
		if(_arg.size()==0)
		{
			_symbol=_name.symbol()+"()";
			return _symbol;
		}
		_symbol+=_name.symbol();
		_symbol+="(";
		for(int i=0;i<_arg.size()-1;i++)
		{
			_symbol=_symbol+_arg[i]->symbol()+", ";
		}
		_symbol=_symbol+_arg[_arg.size()-1]->symbol()+")";
		return _symbol;
	}
	string value()const{
		string _value;
		if(_arg.size()==0)
		{
			_value=_name.symbol()+"()";
			return _value;
		}
		_value+=_name.symbol();
		_value+="(";
		for(int i=0;i<_arg.size()-1;i++)
		{
			_value=_value+_arg[i]->value()+", ";
		}
		_value=_value+_arg[_arg.size()-1]->value()+")";
		return _value;
	}
	bool assignable()const{return _assignable;}
	bool match(Term &term){
		Struct *ps = dynamic_cast<Struct *>(&term);
		if (ps){
      if (!_name.match(ps->_name))
        return false;
      if(_arg.size()!= ps->_arg.size())
        return false;
      for(int i=0;i<_arg.size();i++){
        if(_arg[i]->symbol() != ps->_arg[i]->symbol())
            return false;
		}
      return true;
		}
    return false;
	}
	void assign(Term *term){}
	/*Iterator <Term*> *createIterator(){
		return new StructIterator<Term*>(this);
	}*/
	
	private:
};

#endif