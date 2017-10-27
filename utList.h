#ifndef UTLIST_H
#define UTLIST_H

#include <string>
using std::string;

#include "list.h"
#include "struct.h"
#include "atom.h"
#include "number.h"
#include "variable.h"

// When create a new list without any item
// Then #symbol() of the list should return "[]"
TEST (List, constructor) {
  List l;
  EXPECT_EQ(l.symbol(),"[]");
}

// Given there are two perfect Numbers: 8128, 496
// When create a new list with the perfect Number
// Then #symbol() of the list should return "[496, 8128]"
TEST(List, Numbers) {
	Number n1(8128),n2(496);
	vector<Term *> args = {&n1, &n2};
	List l(args);
	EXPECT_EQ(l.symbol(),"[8128, 496]");
}

// Given there are two atoms: "terence_tao", "alan_mathison_turing"
// When create a new list with the Atoms
// Then #symbol() of the list should return "[terence_tao, alan_mathison_turing]"
TEST(List, Atoms) {
	Atom a1("terence_tao"),a2("alan_mathison_turing");
	vector<Term *> args = {&a1, &a2};
	List l(args);
	EXPECT_EQ(l.symbol(),"[terence_tao, alan_mathison_turing]");
}

// Given there are two variables: X, Y
// When create a new list with the variables
// Then #symbol() of the list should return "[X, Y]"
TEST(List, Vars) {
	Variable X("X"),Y("Y");
	vector<Term *> args = {&X, &Y};
	List l(args);
	EXPECT_EQ(l.symbol(),"[X, Y]");
}

// ?- tom = [496, X, terence_tao].
// false.
TEST(List, matchToAtomShouldFail) {
	Number n(496);
	Variable X("X");
	Atom a("terence_tao"),tom("tom");
	vector<Term *> args = {&n, &X, &a};
	List l(args);
	EXPECT_FALSE(tom.match(l));
}

// ?- 8128 = [496, X, terence_tao].
// false.
TEST(List, matchToNumberShouldFail) {
	Number n1(496),n2(8128);
	Variable X("X");
	Atom a("terence_tao");
	vector<Term *> args = {&n1, &X, &a};
	List l(args);
	EXPECT_FALSE(n2.match(l));
}

// ?- s(X) = [496, X, terence_tao].
// false.
TEST(List, matchToStructShouldFail) {
	Number n(496);
	Variable X("X");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	List l(args);
	vector<Term *> args2 = {&X};
	Struct s(Atom("s"),args2);
	EXPECT_FALSE(s.match(l));
}

// ?- Y = [496, X, terence_tao].
// Y = [496, X, terence_tao].
TEST(List, matchToVarShouldSucceed) {
	Number n(496);
	Variable X("X"),Y("Y");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	List l(args);
	EXPECT_TRUE(Y.match(l));
	EXPECT_EQ(Y.value(),l.value());
}

// ?- X = [496, X, terence_tao].
// false.
TEST(List, matchToVarOccuredInListShouldFail) {
	Number n(496);
	Variable X("X");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	List l(args);
	EXPECT_FALSE(X.match(l));
}

// ?- [496, X, terence_tao] = [496, X, terence_tao].
// true.
TEST(List, matchToSameListShouldSucceed) {
	Number n(496);
	Variable X("X");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	List l1(args), l2(args);
	EXPECT_TRUE(l1.match(l2));
}

// ?- [496, X, terence_tao] = [496, Y, terence_tao].
// true.
TEST(List, matchToSameListWithDiffVarNameShouldSucceed) {
	Number n(496);
	Variable X("X"),Y("Y");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	vector<Term *> args2 = {&n, &Y, &a};
	List l1(args), l2(args2);
	EXPECT_TRUE(l1.match(l2));
}

// ?- [496, X, terence_tao] = [496, 8128, terence_tao].
// X = 8128.
TEST(List, matchToVarToAtominListShouldSucceed) {
	Number n(496),n2(8128);
	Variable X("X");
	Atom a("terence_tao");
	vector<Term *> args = {&n, &X, &a};
	vector<Term *> args2 = {&n, &n2, &a};
	List l1(args), l2(args2);
	EXPECT_TRUE(l1.match(l2));
	EXPECT_EQ(X.value(),"8128");
}

// ?- Y = [496, X, terence_tao], X = alan_mathison_turing.
// Y = [496, alan_mathison_turing, terence_tao],
// X = alan_mathison_turing.
TEST(List, matchVarinListToAtomShouldSucceed) {
	Number n(496);
	Variable X("X"),Y("Y");
	Atom a("terence_tao"),a2("alan_mathison_turing");
	vector<Term *> args = {&n, &X, &a};
	List l(args);
	EXPECT_TRUE(Y.match(l));
	EXPECT_TRUE(X.match(a2));
	EXPECT_EQ(Y.value(),"[496, alan_mathison_turing, terence_tao]");
	EXPECT_EQ(X.value(),"alan_mathison_turing");
}

// Example: 
// ?- [first, second, third] = [H|T].
// H = first, T = [second, third].
TEST(List, headAndTailMatching1) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("first"), l.head()->symbol());
  EXPECT_EQ(string("[second, third]"), l.tail()->value());
}

// Example:
// ?- [first, second, third] = [first, H|T].
// H = second, T = [third].
TEST(List, headAndTailMatching2) {
  Atom f("first"), s("second"), t("third");
  vector<Term *> args = {&f, &s, &t};
  List l(args);

  EXPECT_EQ(string("second"), l.tail()->head()->value());
  EXPECT_EQ(string("[third]"), l.tail()->tail()->value());
}

// ?- [[first], second, third] = [H|T].
// H = [first], T = [second, third].
TEST(List, headAndTailMatching3) {
	Atom f("first"), s("second"), t("third");
	vector<Term *> args = {&f};
	List l(args);
	vector<Term *> args2 = {&l, &s, &t};
	List l2(args2);
	
	EXPECT_EQ("[first]",l2.head()->symbol());
	EXPECT_EQ("[second, third]",l2.tail()->value());
	
}

// ?- [first, second, third] = [first, second, H|T].
// H = third, T = [].
TEST(List, headAndTailMatching4) {
	Atom f("first"), s("second"), t("third");
	vector<Term *> args = {&f, &s, &t};
	List l(args);
	
	EXPECT_EQ("third",l.tail()->tail()->head()->value());
	EXPECT_EQ("[]",l.tail()->tail()->tail()->value());
}
 
// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing head in an empty list" as an exception.
TEST (List, emptyExecptionOfHead) {
	List l;
	try
	{
		l.head()->value();
	}
	catch(string s)
	{
		EXPECT_EQ(s,"Accessing head in an empty list");
	}
}

// Given there is a empty list
// When client still want to get the head of list
// Then it should throw a string: "Accessing tail in an empty list" as an exception.
TEST (List, emptyExecptionOfTail) {
	List l;
	try
	{
		l.tail()->value();
	}
	catch(string s)
	{
		EXPECT_EQ(s,"Accessing tail in an empty list");
	}
}




#endif