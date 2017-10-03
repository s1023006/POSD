#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"
#include "match.cpp"
//test Number.value()
TEST (Number,ctor) {
	Number twenty_five(25);
	ASSERT_EQ(twenty_five.value(),"25");
}
//test Number.symbol()
TEST (Number, symbol) {
	Number twenty_five(25);
	ASSERT_EQ(twenty_five.symbol(),"25");
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number twenty_five1(25);
	Number twenty_five2(25);
	ASSERT_TRUE(match(twenty_five1,twenty_five2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number twenty_five(25);
	Number zero(0);
	ASSERT_FALSE(match(twenty_five,zero));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_FALSE(match(twenty_five,tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number twenty_five(25);
	Variable X("X");
	ASSERT_TRUE(match(twenty_five,X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_FALSE(match(tom,twenty_five));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(match(tom,X));
	ASSERT_EQ(X.value(),tom.symbol());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(match(X,tom));
	ASSERT_TRUE(match(tom,X));
	ASSERT_EQ(X.value(),tom.symbol());
	
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Variable X("X");
	Atom tom("tom");
	Atom jerry("jerry");
	ASSERT_TRUE(match(X,jerry));
	ASSERT_FALSE(match(tom,X));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
	Variable X("X");
	Number five(5);
	ASSERT_TRUE(match(X,five));
	ASSERT_EQ(X.value(),five.value());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
	Variable X("X");
	Number twenty_five(25);
	Number hundred(100);
	ASSERT_TRUE(match(X,twenty_five));
	ASSERT_FALSE(match(X,hundred));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
	Variable X("X");
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_TRUE(match(X,tom));
	ASSERT_FALSE(match(X,twenty_five));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
	Variable X("X");
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_TRUE(match(tom,X));
	ASSERT_FALSE(match(twenty_five,X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
	Variable X("X");
	Atom tom1("tom"),tom2("tom");
	ASSERT_TRUE(match(X,tom1));
	ASSERT_TRUE(match(X,tom2));
}
#endif
