/*
 * ListenerThread.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef LISTENERTHREAD_H_
#define LISTENERTHREAD_H_

//#include "TcpServer.h"

namespace wanaka {

class TcpServer;

class ListenerThread {
public:
	ListenerThread(TcpServer* server);
	virtual ~ListenerThread();

	/**
	 *  1. listen for new Socket join, then call back handler.sessionCreated()
	 *
	 * */
	void run();

	void start();
private:
	bool threadStarted;
	TcpServer *server;
};

} /* namespace wanaka */
#endif /* LISTENERTHREAD_H_ */
