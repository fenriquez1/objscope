/*
 * BundleObject.h
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#ifndef BUNDLEOBJECT_H_
#define BUNDLEOBJECT_H_

#include <string>
#include <iostream>

class BundleObject {
public:
	explicit BundleObject(std::string pStr);
	virtual ~BundleObject();

	std::string mPayload;
};

#endif /* BUNDLEOBJECT_H_ */
