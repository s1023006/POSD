#ifndef UTTERM_H
#define UTTERM_H
#include "number.h"
#include "atom.h"
#include "variable.h"
#include "match.cpp"
//test Number.value()
TEST (Number,ctor) {
	Number twenty_five("25");
	ASSERT_EQ(twenty_five.value(),"25");
}
//test Number.symbol()
TEST (Number, symbol) {
	Number twenty_five("25");
	ASSERT_EQ(twenty_five.symbol(),"25");
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Number twenty_five1("25");
	Number twenty_five2("25");
	ASSERT_TRUE(match(twenty_five1,twenty_five2));
}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Number twenty_five("25");
	Number zero("0");
	ASSERT_FALSE(match(twenty_five,zero));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Number twenty_five("25");
	Atom tom("tom");
	ASSERT_FALSE(match(twenty_five,tom));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Number twenty_five("25");
	Variable X("X");
	ASSERT_TRUE(match(X,twenty_five));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Number twenty_five("25");
	Atom tom("tom");
	ASSERT_FALSE(match(tom,twenty_five));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {

}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
 
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {

}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {

}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {

}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){

}
#endif
