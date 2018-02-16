/*
 * BundleObject.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#include "BundleObject.h"

static int positiveCounter = 0;
static int negativeCounter = 0;

BundleObject::BundleObject(std::string pStr) {
	mPayload = pStr;
	positiveCounter++;
	std::cout << "BundleObject = " << positiveCounter << std::endl;

}

BundleObject::~BundleObject() {
	negativeCounter ++;
	std::cout << "~BundleObject = " << negativeCounter  << std::endl;
}

