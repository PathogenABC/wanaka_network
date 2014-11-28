/*
 * PojoSenderThread.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */
#include <thread>
#include "PojoSenderThread.h"
#include "Session.h"

namespace wanaka {

PojoSenderThread::PojoSenderThread(TerminalProtocol *terminal) :
		threadStarted(false) {
	this->terminal = terminal;
}

PojoSenderThread::~PojoSenderThread() {

}

void PojoSenderThread::start() {
	if (!threadStarted) {
		std::thread thread(&PojoSenderThread::run, this);
		thread.detach(); // start
		threadStarted = true;
	}
}

void PojoSenderThread::run() {
//	while (terminal->isRunning()) {
//		if (waitForSendingPojoBeans.empty()) continue;
//		else {
//			lock.lock();
//			PojoTransferBean *bean = waitForSendingPojoBeans.front();
//			waitForSendingPojoBeans.pop();
//			lock.unlock();
//			bean->getSession()->writeSyn(bean->getPojo());	// 同步发送出去
//		}
//	}
}

void PojoSenderThread::pushBean(PojoTransferBean* bean) {
	lock.lock();
	waitForSendingPojoBeans.push(bean);
	lock.unlock();
}

}
/* namespace wanaka */
