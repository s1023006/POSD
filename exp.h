#ifndef EXP_H
#define EXP_H

#include "atom.h"

class Exp {
public:
  virtual bool evaluate() = 0;
  virtual string getEvaluateString() {return "";}
};


class MatchExp : public Exp {
public:
  MatchExp(Term* left, Term* right): _left(left), _right(right){

  }

  bool evaluate(){
    return _left->match(*_right);
  }
  string getEvaluateString(){
	if(evaluate()&&_left->symbol()==_right->symbol())
		return "true";
	else if(!evaluate())
		return "false";
    return _left->symbol() + " = " + _right->value() ;
  }
  
private:
  Term* _left;
  Term* _right;
};

class ConjExp : public Exp {
public:
  ConjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() && _right->evaluate());
  }

  string getEvaluateString(){
    evaluate();
    if (_left->getEvaluateString() == "true" && _right->getEvaluateString() == "true")
      return "true";
    else if (_left->getEvaluateString() == "false" || _right->getEvaluateString() == "false")
      return "false";
    else if (_left->getEvaluateString() == "true")
      return _right->getEvaluateString();
    else if (_right->getEvaluateString() == "true")
      return _left->getEvaluateString();
    else if (_left->getEvaluateString().find(_right->getEvaluateString()) != string::npos)
      return _left->getEvaluateString();
    else
      return _left->getEvaluateString() + ", " + _right->getEvaluateString();
  }

private:
  Exp * _left;
  Exp * _right;
};

class DisjExp : public Exp {
public:
  DisjExp(Exp *left, Exp *right) : _left(left), _right(right) {

  }

  bool evaluate() {
    return (_left->evaluate() || _right->evaluate());
  }
  string getEvaluateString(){
	  evaluate();
    if (_left->getEvaluateString() == "false")
      return _right->getEvaluateString();
    else if (_right->getEvaluateString() == "false")
      return _left->getEvaluateString();
    else
      return _left->getEvaluateString() + "; " + _right->getEvaluateString();
  }

private:
  Exp * _left;
  Exp * _right;
};
#endif
