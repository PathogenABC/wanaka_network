/*
 * TcpClient.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef TCPCLIENT_H_
#define TCPCLIENT_H_

#include "ClientProtocol.h"
#include <string>

namespace wanaka {

class Session;
class HandlerProtocol;
class DeserializerProtocol;
class SerializerProtocol;

class TcpClient: public ClientProtocol {
private:
	Session *session;
	HandlerProtocol *handler;
	DeserializerProtocol *deserializer;
	SerializerProtocol *serializer;
	PojoSenderThread *senderThread;
public:
	TcpClient(std::string ip, int port);
	virtual ~TcpClient();

	virtual void setHandler(HandlerProtocol *handler);
	virtual HandlerProtocol * getHandler();
	virtual void setDeserializer(DeserializerProtocol *deserializer);
	virtual DeserializerProtocol * getDeserializer();
	virtual void setSerializer(SerializerProtocol *serializer);
	virtual SerializerProtocol * getSerializer();

	virtual Session* getSession();

	virtual bool start(); // connect
	virtual bool isConnected();

	virtual bool isRunning() {return isConnected();}
	virtual PojoSenderThread *getSenderThread();
};

} /* namespace wanaka */
#endif /* TCPCLIENT_H_ */
