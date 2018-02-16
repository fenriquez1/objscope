/*
 * main.cpp
 *
 *  Created on: Oct 5, 2017
 *      Author: j35333
 */

#include <iostream>
#include <pthread.h>

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

	while (i < 20) {
		pthread_mutex_lock(&receiver.recvMutex);
		if (!receiver.recvQ.empty()) {
			BundleObject & tBundleObject = receiver.recvQ.front();
			receiver.recvQ.pop();
			std::cout << "Processed Bundle: " << tBundleObject.mPayload << std::endl;
			i++;
		}
		pthread_mutex_unlock(&receiver.recvMutex);
		usleep(7500);
	}

	pthread_join(sender.sendBundlesThread, NULL);
	pthread_join(receiver.recvBundlesThread, NULL);

	return 0;
}
