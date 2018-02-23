/*
 * BundleReceiver.h
 *
 *  Created on: Oct 5, 2017
 *      Author: Francisco Enriquez
 */

#ifndef BUNDLERECEIVER_H_
#define BUNDLERECEIVER_H_

#include <queue>
#include <thread>
#include <iostream>
#include <unistd.h>

#include "BundleObject.h"

class BundleObject;

class BundleReceiver {
public:
	BundleReceiver();
	virtual ~BundleReceiver();

	std::thread recvBundlesThread;
	std::mutex recvMutex;
	std::queue<BundleObject> recvQ;

private:
	void startBundleReceiver();
};

#endif /* BUNDLERECEIVER_H_ */
