#ifndef UTTERM_H
#define UTTERM_H
#include "Number.h"
//test Number.value()
TEST (Number,ctor) {
	Atom Number("Number","number");
	ASSERT_EQ("number",Number.value());
}
//test Number.symbol()
TEST (Number, symbol) {
	Atom Number("Number","number");
	ASSERT_EQ("Number",Number.symbol());
}
//?- 25=25.
//true.
TEST (Number, matchSuccess) {
	Atom temp("25");
	ASSERT_TRUE(temp.match("25"));

}
//?- 25=0.
//false.
TEST (Number, matchFailureDiffValue) {
	Atom temp("25");
	ASSERT_FALSE(temp.match("0"));
}
//?- 25=tom.
//false.
TEST (Number, matchFailureDiffConstant) {
	Atom temp("25");
	ASSERT_FALSE(temp.match("tom"));
}
//?- 25=X.
//true.
TEST (Number, matchSuccessToVar) {
	Atom temp("25");
	Atom X("X","25");
	ASSERT_TRUE(temp.match(X));
}

//?- tom=25.
//false.
TEST (Atom, matchFailureDiffConstant) {
	Atom temp("tom");
	ASSERT_FALSE(temp.match("25"));
}

// ?- tom = X.
// X = tom.
TEST (Atom, matchSuccessToVar) {
	Atom temp("tom");
	Atom X("X","tom");
	ASSERT_EQ(X.value(),temp.value());
}

// ?- X=tom, tom=X.
// X = tom.
TEST (Atom, matchSuccessToVarInstantedToDiffConstant) {
	Atom X("X","tom");
	Atom temp(X.value());
	ASSERT_EQ(X.value(),temp.value());
}

// ?- X=jerry, tom=X.
// false.
TEST (Atom, matchFailureToVarInstantedToDiffConstant) {
	Atom X("X","jerry");
	Atom temp("tom");
	ASSERT_FALSE(X.match(temp));
}

// ?- X = 5.
// X = 5.
TEST (Var, matchSuccessToNumber) {
	Atom X("X","5");
	ASSERT_EQ(X.value(),"5");
}

// ?- X=25, X= 100.
// false.
TEST (Var, matchFailureToTwoDiffNumbers) {
	Atom X("X","25");
	ASSERT_FALSE(X.match("100"));
}

// ?- X=tom, X= 25.
// false.
TEST (Var, matchSuccessToAtomThenFailureToNumber) {
	Atom X("X","tom");
	ASSERT_FALSE(X.match("25"));
}
//?- tom=X, 25=X.
//false.
TEST (Var, matchSuccessToAtomThenFailureToNumber2) {
	Atom X("X","tom");
	ASSERT_FALSE(X.match("25"));
}
//?- X=tom, X=tom.
//true.
TEST(Var, reAssignTheSameAtom){
	Atom X("X","tom");
	ASSERT_TRUE(X.match("tom"));
}
#endif
