#ifndef PARSER_H
#define PARSER_H
#include <string>
using std::string;

#include "atom.h"
#include "variable.h"
#include "global.h"
#include "scanner.h"
#include "struct.h"
#include "list.h"
#include "node.h"
#include <iostream>

class Parser{
public:
  Parser(Scanner scanner) : _scanner(scanner){}
  Term* createTerm(){
    int token = _scanner.nextToken();
    _currentToken = token;
    if(token == VAR){
      return new Variable(symtable[_scanner.tokenValue()].first);
    }else if(token == NUMBER){
      return new Number(_scanner.tokenValue());
    }else if(token == ATOM || token == ATOMSC){
      Atom* atom = new Atom(symtable[_scanner.tokenValue()].first);
      if(_scanner.currentChar() == '(' ) {
        return structure();
      }
      else
        return atom;
    }
    else if(token == '['){
      return list();
    }

    return nullptr;
  }

    Term * structure() {
    Atom structName = Atom(symtable[_scanner.tokenValue()].first);
    int startIndexOfStructArgs = _terms.size();
    _scanner.nextToken();
    createTerms();
    if(_currentToken == ')')
    {
      vector<Term *> args(_terms.begin() + startIndexOfStructArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfStructArgs, _terms.end());
      return new Struct(structName, args);
    } else {
      throw string("unexpected token");
    }
  }

  Term * list() {
    int startIndexOfListArgs = _terms.size();
    createTerms();
    if(_currentToken == ']')
    {
      vector<Term *> args(_terms.begin() + startIndexOfListArgs, _terms.end());
      _terms.erase(_terms.begin() + startIndexOfListArgs, _terms.end());
      return new List(args);
    } else {
      throw string("unexpected token");
    }
  }
  
/*  
  vector<Term*> getArgs()
  {
    Term* term = createTerm();
    vector<Term*> args;
    if(term!=nullptr)
      args.push_back(term);
	if((_currentToken == ']'||_currentToken == ')')&& term == nullptr)
	  return args;
    while((_currentToken = _scanner.nextToken()) == ',') {
      args.push_back(createTerm());
    }
    return args;
  }
*/
	
	void createTerms()
	{
		Term* term = createTerm();
		if(term!=nullptr)
		{
		  _terms.push_back(term);
		  while((_currentToken = _scanner.nextToken()) == ',') {
			_terms.push_back(createTerm());
		  }
		}
	}

	vector<Term*> getTerms()
	{
		return _terms;
	}

	void matchings()
	{
		Term* term=createTerm();
		if(term!=nullptr)
		{
			_terms.push_back(term);
			while((_currentToken = _scanner.nextToken()) == '=' || _currentToken == ',' || _currentToken == ';')
			{
				if(_currentToken=='=')
				{
					Node *tleft=new Node(TERM,_terms.back());
					_terms.push_back(createTerm());
					Node *tright=new Node(TERM,_terms.back());
					_expressionTree = new Node(EQUALITY,0,tleft,tright);
				}
				else if(_currentToken == ',')
				{
					Node *tleft=_expressionTree;
					matchings();
					Node *tright=_expressionTree;
					_expressionTree = new Node(COMMA,0,tleft,tright);
				}
				else if(_currentToken == ';')
				{
					Node *tleft=_expressionTree;
					matchings();
					Node *tright=_expressionTree;
					_expressionTree = new Node(SEMICOLON,0,tleft,tright);
				}
			}
		}
	}
	
	Node * expressionTree()
	{
		return _expressionTree;
	}
	
private:
  Scanner _scanner;
  int _currentToken;
  vector<Term*> _terms;
  Node *_expressionTree;
  
};
#endif