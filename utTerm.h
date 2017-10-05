#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"

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
	ASSERT_TRUE(twenty_five1.match(twenty_five2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number twenty_five(25);
	Number zero(0);
	ASSERT_FALSE(twenty_five.match(zero));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_FALSE(twenty_five.match(tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number twenty_five(25);
	Variable X("X");
	ASSERT_TRUE(twenty_five.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_FALSE(tom.match(twenty_five));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(tom.match(X));
	ASSERT_EQ(X.value(),tom.symbol());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom tom("tom");
	Variable X("X");
	ASSERT_TRUE(X.match(tom));
	ASSERT_TRUE(tom.match(X));
	ASSERT_EQ(X.value(),tom.symbol());
	
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Variable X("X");
	Atom tom("tom");
	Atom jerry("jerry");
	ASSERT_TRUE(X.match(jerry));
	ASSERT_FALSE(tom.match(X));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
	Variable X("X");
	Number five(5);
	ASSERT_TRUE(X.match(five));
	ASSERT_EQ(X.value(),five.value());
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
	Variable X("X");
	Number twenty_five(25);
	Number hundred(100);
	ASSERT_TRUE(X.match(twenty_five));
	ASSERT_FALSE(X.match(hundred));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
	Variable X("X");
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_TRUE(X.match(tom));
	ASSERT_FALSE(X.match(twenty_five));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
	Variable X("X");
	Number twenty_five(25);
	Atom tom("tom");
	ASSERT_TRUE(tom.match(X));
	ASSERT_FALSE(twenty_five.match(X));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
	Variable X("X");
	Atom tom1("tom"),tom2("tom");
	ASSERT_TRUE(X.match(tom1));
	ASSERT_TRUE(X.match(tom2));
}
#endif
