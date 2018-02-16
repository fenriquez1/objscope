/*
 * BundleReceiver.h
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#ifndef BUNDLERECEIVER_H_
#define BUNDLERECEIVER_H_

#include <queue>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include "BundleObject.h"

class BundleObject;

class BundleReceiver {
public:
	BundleReceiver();
	virtual ~BundleReceiver();

	pthread_t recvBundlesThread;
	pthread_mutex_t recvMutex;
	std::queue<BundleObject> recvQ;
};

#endif /* BUNDLERECEIVER_H_ */
