/*
 * TerminalProtocol.h
 *
 *  Created on: 2014-11-28
 *      Author: Chris
 */

#ifndef TERMINALPROTOCOL_H_
#define TERMINALPROTOCOL_H_

namespace wanaka {

class HandlerProtocol;
class DeserializerProtocol;
class SerializerProtocol;
class PojoSenderThread;

class TerminalProtocol {
public:
	virtual ~TerminalProtocol();

	virtual void setHandler(HandlerProtocol *handler) = 0;
	virtual HandlerProtocol * getHandler() = 0;
	virtual void setDeserializer(DeserializerProtocol *deserializer) = 0;
	virtual DeserializerProtocol * getDeserializer() = 0;
	virtual void setSerializer(SerializerProtocol *serializer) = 0;
	virtual SerializerProtocol * getSerializer() = 0;

	virtual bool start() = 0; // connect
	virtual bool isRunning() = 0;

	virtual PojoSenderThread *getSenderThread() = 0;
};

} /* namespace wanaka */
#endif /* TERMINALPROTOCOL_H_ */
