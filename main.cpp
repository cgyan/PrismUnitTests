/*
 * main.cpp
 *
 *  Created on: Dec 12, 2016
 *      Author: iainhemstock
 */

#include "gtest/gtest.h"
#include <iostream>
#include <vector>
using namespace std;
using namespace ::testing;

int main(int argc, char * argv[]) {



	InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
