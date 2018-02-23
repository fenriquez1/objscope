/*
 * BundleSender.h
 *
 *  Created on: Oct 5, 2017
 *      Author: Francisco Enriquez
 */

#ifndef BUNDLESENDER_H_
#define BUNDLESENDER_H_

#include <thread>
#include <queue>
#include <iostream>
#include <unistd.h>

#include "BundleObject.h"

class BundleObject;

class BundleSender {
public:
	BundleSender();
	virtual ~BundleSender();

	bool sendBundle(BundleObject bundle);

	std::thread sendBundlesThread;
	std::mutex sendMutex;
	std::queue<BundleObject> sendQ;

private:
	void startBundleSender();
};

#endif /* BUNDLESENDER_H_ */
