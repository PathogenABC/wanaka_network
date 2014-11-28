/*
 * ListenerThread.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include <stdio.h>
#include <assert.h>
#include <thread>
#include <functional>

#include "ListenerThread.h"
#include "TcpServer.h"
#include "ServerSocket.h"
#include "Session.h"
#include "HandlerProtocol.h"
#include "SessionManager.h"

namespace wanaka {

ListenerThread::ListenerThread(TcpServer* server) : threadStarted(false) {
	assert(server);
}

ListenerThread::~ListenerThread() {

}

void ListenerThread::run() {
	ServerSocket * ss = server->getServerSocket();
	while (server->isStarted()) {
		Socket * client = ss->accept();
		if (client) {
			Session * session = new Session(server, client);
			server->getManager()->putSession(session); // 放入队列
			server->getHandler()->sessionCreated(session); // 回调函数
		}
	}
}

void ListenerThread::start() {
	if (!threadStarted) {
		std::thread threadNew(&ListenerThread::run, this);
		threadNew.detach(); // start
		threadStarted = true;
	}
}

} /* namespace wanaka */
