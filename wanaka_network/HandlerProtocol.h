/*
 * HandlerProtocol.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef HANDLERPROTOCOL_H_
#define HANDLERPROTOCOL_H_

namespace wanaka {

class Session;
class PojoProtocol;

class HandlerProtocol {
public:
	virtual ~HandlerProtocol();

	virtual void sessionCreated(Session *session) = 0;
	virtual void sessionClosed(Session *session) = 0;
	virtual void pojoSent(Session *session, PojoProtocol *pojo) = 0;
	virtual void pojoReceived(Session *session, PojoProtocol *pojo) = 0;
	virtual void exceptionCaught(Session *session) = 0;
};

} /* namespace wanaka */
#endif /* HANDLERPROTOCOL_H_ */
