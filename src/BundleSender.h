/*
 * BundleSender.h
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#ifndef BUNDLESENDER_H_
#define BUNDLESENDER_H_

#include <pthread.h>
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

	pthread_t sendBundlesThread;
	pthread_mutex_t sendMutex;
	std::queue<BundleObject> sendQ;
};

#endif /* BUNDLESENDER_H_ */
