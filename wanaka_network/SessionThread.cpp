/*
 * ChannelThread.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "SessionThread.h"
#include <assert.h>
#include <thread>
#include "TerminalProtocol.h"
#include "PojoProtocol.h"
#include "HandlerProtocol.h"
#include "Session.h"
#include "DeserializerProtocol.h"

namespace wanaka {

SessionThread::SessionThread(TerminalProtocol *terminal, Session *session) : threadStarted(false) {
	assert(terminal);
	this->terminal = terminal;
	this->session = session;
}

SessionThread::~SessionThread() {

}

void SessionThread::run() {
	while (terminal->isRunning()) {
		PojoProtocol * pojo = terminal->getDeserializer()->deserialize(session);
		if (NULL == pojo) {
			terminal->getHandler()->exceptionCaught(session);		// exceptionCaught
		} else {
			terminal->getHandler()->pojoReceived(session, pojo);		// pojoReceived
		}
	}
	terminal->getHandler()->sessionClosed(session);					// sessionClosed
}

void SessionThread::start() {
	if (!threadStarted) {
		std::thread thread(&SessionThread::run ,this);
		thread.detach();	// start
		threadStarted = true;
	}
}

}
 /* namespace wanaka */
