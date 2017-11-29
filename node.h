#ifndef NODE_H
#define NODE_H

#include "term.h"

enum Operators 
{
	SEMICOLON,	//;
	COMMA,		//,
	EQUALITY,	//=
	TERM		//term
};

class Node {
public:
  //Node(Operators op):payload(op), term(0), left(0), right(0) {}
  Node(Operators op, Term *t=0, Node *l=0, Node *r=0):payload(op), term(t), left(l), right(r) {}
  
  //Node(Operators op,Term *t):payload(op), term(t){}

  Operators payload;
  Term *term;
  Node *left;
  Node *right;
  bool bool_value=false;
  
  bool evaluate()
  {
	  switch(payload)
	  {
		  case EQUALITY:
			bool_value=left->term->match(*(right->term));
			break;
		  case COMMA:
			left->evaluate();
			right->evaluate();
			bool_value=(left->bool_value && right->bool_value);
			break;
		  case SEMICOLON:
			left->evaluate();
			right->evaluate();
			bool_value=(left->bool_value || right->bool_value);
			break;
	  }
	  return bool_value;
  }
  
};

#endif