/*
 * PojoSenderThread.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef POJOSENDERTHREAD_H_
#define POJOSENDERTHREAD_H_

#include <queue>
#include <mutex>

namespace wanaka {

class PojoTransferBean;
class TerminalProtocol;

class PojoSenderThread {
private:
	std::queue<PojoTransferBean *> waitForSendingPojoBeans;		// send bean queue

	TerminalProtocol *terminal;
	bool threadStarted;

	std::mutex lock;		// 多线程锁
public:
	PojoSenderThread(TerminalProtocol *terminal);
	virtual ~PojoSenderThread();

	void start();

	/** while
	 * 1. detect the bean queue
	 * 2. pop the top pojo
	 * 3. sequencely send the pojo
	 * 4. callback the session.pojoSent
	 *
	 * */
	void run();

	void pushBean(PojoTransferBean *bean);
};

} /* namespace wanaka */
#endif /* POJOSENDERTHREAD_H_ */
