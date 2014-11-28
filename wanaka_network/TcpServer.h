/*
 * TcpServer.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#include "ServerProtocol.h"
#include <string>

namespace wanaka {

class Session;
class ServerSocket;
class SessionManager;
class PojoSenderThread;

class TcpServer: public ServerProtocol {
public:
	TcpServer(int port);
	virtual ~TcpServer();

	virtual void setHandler(HandlerProtocol *handler);
	virtual HandlerProtocol * getHandler();
	virtual void setDeserializer(DeserializerProtocol *deserializer);
	virtual DeserializerProtocol * getDeserializer();
	virtual void setSerializer(SerializerProtocol *serializer);
	virtual SerializerProtocol * getSerializer();

	virtual SessionManager * getManager() const;

	virtual Session * getSession(std::string ip);
	virtual bool cutSession(std::string ip);		// remove session by the specified ip
	virtual bool start(); // accept

	// setter and getter
	ServerSocket* getServerSocket() const {	return serverSocket;}
	void setServerSocket(ServerSocket* serverSocket) {this->serverSocket = serverSocket;}

	virtual bool isStarted() const {return started;}
	virtual void setStarted(bool started) {	this->started = started;}

	virtual bool isRunning() {return isStarted();}

	virtual PojoSenderThread *getSenderThread();
private:
	SessionManager *manager;
	HandlerProtocol *handler;
	DeserializerProtocol *deserializer;
	SerializerProtocol *serializer;

	bool started;
	ServerSocket *serverSocket;
	PojoSenderThread *senderThread;
};

} /* namespace wanaka */
#endif /* TCPSERVER_H_ */
