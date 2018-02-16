/*
 * BundleSender.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#include "BundleSender.h"

//pthread_mutex_t sendMutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t *sSendMutexPtr;

static void *startBundleSender(void *value) {
	std::queue<BundleObject> *outQ = (std::queue<BundleObject>*) value;
	int i = 0;

	while(i < 10) {
		pthread_mutex_lock(sSendMutexPtr);
		if (!outQ->empty()) {
			BundleObject & tBundleObject = outQ->front();
			outQ->pop();
			std::cout << "Sent Bundle: " << tBundleObject.mPayload << std::endl;
			i++;
		}
		pthread_mutex_unlock(sSendMutexPtr);

		usleep(5000);

	}

	return NULL;
}

BundleSender::BundleSender() {
	sendMutex = PTHREAD_MUTEX_INITIALIZER;
	sSendMutexPtr = &sendMutex;
	if (pthread_create(&sendBundlesThread, NULL, startBundleSender,
			(void *) &this->sendQ) < 0) {
		exit(1);
	}
}

BundleSender::~BundleSender() {
	// TODO Auto-generated destructor stub
}

bool BundleSender::sendBundle(BundleObject bundle) {
	pthread_mutex_lock(&sendMutex);
	this->sendQ.push(bundle);
	pthread_mutex_unlock(&sendMutex);
	return true;
}

