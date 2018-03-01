/*
 * BundleReceiver.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: Francisco Enriquez
 */

#include "BundleReceiver.h"

void BundleReceiver::startBundleReceiver() {

	std::string tBundle = std::string("Bundle");
	int i = 10;

	timespec ts;
	ts.tv_nsec = 750000000;
	ts.tv_sec = 0;
	while(i++ < 20) {
		tBundle.clear();
		tBundle.append("Bundle");
		tBundle.append(std::to_string(i));

		this->recvMutex.lock();
			this->recvQ.push(BundleObject(tBundle));
		this->recvMutex.unlock();

		std::cout << "Received Bundle: " << tBundle << std::endl;
		nanosleep(&ts, nullptr);
	}
}

BundleReceiver::BundleReceiver() {
	recvBundlesThread = std::thread(&BundleReceiver::startBundleReceiver, this);
}

BundleReceiver::~BundleReceiver() {
	// TODO Auto-generated destructor stub
}

