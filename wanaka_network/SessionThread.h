/*
 * ChannelThread.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef CHANNELTHREAD_H_
#define CHANNELTHREAD_H_

namespace wanaka {

class TerminalProtocol;
class Session;

class SessionThread {
public:
	SessionThread(TerminalProtocol *terminal, Session *session);
	virtual ~SessionThread();

	/**
	 *  while
	 * 1. listen for the new Pojo comes from this channel, then callback handler.pojoReceived()
	 * 2. if excepted, callback handler.exceptionCaught()
	 *
	 * */
	void run();

	void start();
private:
	TerminalProtocol *terminal;
	bool threadStarted;
	Session *session;
};

} /* namespace wanaka */
#endif /* CHANNELTHREAD_H_ */
