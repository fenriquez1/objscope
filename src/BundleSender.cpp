/*
 * BundleSender.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: Francisco Enriquez
 */

#include "BundleSender.h"

void BundleSender::startBundleSender() {

	int i = 0;

	while(i < 10) {
		sendMutex.lock();
		if (!sendQ.empty()) {
			BundleObject & tBundleObject = sendQ.front();
			sendQ.pop();
			std::cout << "Sent Bundle: " << tBundleObject.mPayload << std::endl;
			i++;
		}
		sendMutex.unlock();

		usleep(5000);

	}
}

BundleSender::BundleSender() {
	sendBundlesThread = std::thread(&BundleSender::startBundleSender, this);
}

BundleSender::~BundleSender() {
	// TODO Auto-generated destructor stub
}

bool BundleSender::sendBundle(BundleObject bundle) {
	sendMutex.lock();
	sendQ.push(bundle);
	sendMutex.unlock();
	return true;
}

