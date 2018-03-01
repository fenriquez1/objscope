/*
 * main.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: Francisco Enriquez
 */

#include <iostream>
#include <pthread.h>
#include <time.h>

#include "BundleObject.h"
#include "BundleReceiver.h"
#include "BundleSender.h"


int main(int argc, char*argv[]) {

	BundleReceiver receiver;
	BundleSender sender;
	std::string tBundle = std::string("Bundle");
	int i = 0;

	while (i++ < 10) {
		tBundle.clear();
		tBundle.append("Bundle");
		tBundle.append(std::to_string(i));
		sender.sendBundle(BundleObject(tBundle));
	}

	timespec ts;
	ts.tv_nsec = 750000000;
	ts.tv_sec = 0;
	while (i < 20) {
		receiver.recvMutex.lock();
		if (!receiver.recvQ.empty()) {
			BundleObject & tBundleObject = receiver.recvQ.front();
			receiver.recvQ.pop();
			std::cout << "Processed Bundle: " << tBundleObject.mPayload << std::endl;
			i++;
		}
		receiver.recvMutex.unlock();
		nanosleep(&ts, nullptr);
	}

	sender.sendBundlesThread.join();
	receiver.recvBundlesThread.join();

	return 0;
}
