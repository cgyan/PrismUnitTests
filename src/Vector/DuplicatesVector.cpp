/*
 * DuplicatesVector.cpp
 * v0.*
 *
 *  Created on: 18 Dec 2016
 *      Author: iainhemstock
 */

#include "gtest/gtest.h"
#include <prism/PVector>
#include <prism/h/global.h>
using namespace ::testing;

PRISM_BEGIN_NAMESPACE
PRISM_BEGIN_TEST_NAMESPACE

//=============================================================================
// DuplicatesVector is a class that contains duplicate elements
//=============================================================================
class DuplicatesVector : public Test {
public:
	PVector<int> v;

	void SetUp() {
		setCapacityToTen();
		addElementsToVector();
	}

	void setCapacityToTen() {
		v.reserve(10);
	}

	void addElementsToVector() {
		v.addAtEnd(30);
		v.addAtEnd(1);
		v.addAtEnd(31);
		v.addAtEnd(32);
		v.addAtEnd(1);
		v.addAtEnd(33);
	}
};

TEST_F(DuplicatesVector,
AnswersFirstIndexOfValueSearchingFromSpecifiedIndex) {
	int indexOne = 1;
	int valueToFind = 1;
	int startIndex = 1;

	ASSERT_EQ(indexOne, v.indexOf(valueToFind, startIndex));

	int indexFour = 4;
	startIndex = 2;

	ASSERT_EQ(indexFour, v.indexOf(valueToFind, startIndex));
}

PRISM_END_TEST_NAMESPACE
PRISM_END_NAMESPACE











