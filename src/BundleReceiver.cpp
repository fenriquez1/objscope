/*
 * BundleReceiver.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#include "BundleReceiver.h"

//pthread_mutex_t recvMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t * sRecvMutexPtr;

static void *startBundleReceiver(void *value) {
	std::queue<BundleObject> *inQ = (std::queue<BundleObject>*) value;
	std::string tBundle = std::string("Bundle");
	int i = 10;

	while(i++ < 20) {
		tBundle.clear();
		tBundle.append("Bundle");
		tBundle.append(std::to_string(i));

		pthread_mutex_lock(sRecvMutexPtr);
			inQ->push(BundleObject(tBundle));
		pthread_mutex_unlock(sRecvMutexPtr);

		std::cout << "Received Bundle: " << tBundle << std::endl;
		usleep(75000);
	}

	return NULL;
}

BundleReceiver::BundleReceiver() {
	recvMutex = PTHREAD_MUTEX_INITIALIZER;
	sRecvMutexPtr = &recvMutex;
	if (pthread_create(&recvBundlesThread, NULL, startBundleReceiver,
			(void *) &this->recvQ) < 0) {
		exit(1);
	}
}

BundleReceiver::~BundleReceiver() {
	// TODO Auto-generated destructor stub
}

