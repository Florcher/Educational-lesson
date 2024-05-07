#include "ComparisonTests.h"
#include "Comparison.h"
#include "Myassert.h"

void ComparisonTests::testEqual() {
	myassert(IsEqual(1.43, 1.43) == 1);
	myassert(IsEqual(1.32, -71.3) == 0);
}

void ComparisonTests::testGreater() {
	myassert(Greater(3.213, 0.998) == 1);
	myassert(Greater(-1.32, 7.43) == 0);
}

void ComparisonTests::testLess() {
	myassert(Less(-23.32, 2.48) == 1);
	myassert(Less(4.3213, 0.198) == 0);
	myassert(Less(0, 0) == 0);
}

void ComparisonTests::testGreaterOrEqual() {
	myassert(GreaterOrEqual(1.39, 0.78) == 1);
	myassert(GreaterOrEqual(0.21, 0.21) == 1);
	myassert(GreaterOrEqual(-6.43, 9.88) == 0);
}

void ComparisonTests::testLessOrEqual() {
	myassert(LessOrEqual(-7.54, 6.88) == 1);
	myassert(LessOrEqual(-2.33, -2.33) == 1);
	myassert(LessOrEqual(5.67, 2.12) == 0);
}