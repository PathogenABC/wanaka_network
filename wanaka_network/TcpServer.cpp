/*
 * TcpServer.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "TcpServer.h"
#include <stdlib.h>
#include <assert.h>

#include "Session.h"
#include "ServerSocket.h"
#include "SessionManager.h"
#include "PojoSenderThread.h"
#include "ListenerThread.h"

namespace wanaka {

TcpServer::TcpServer(int port) : handler(NULL), deserializer(NULL), serializer(NULL) {
	serverSocket = new ServerSocket(port);
	manager = new SessionManager();
	senderThread = new PojoSenderThread(this);
}

TcpServer::~TcpServer() {

}

void TcpServer::setHandler(HandlerProtocol* handler) {
	assert(handler);
	this->handler = handler;
}

HandlerProtocol* TcpServer::getHandler() {
	return handler;
}

void TcpServer::setDeserializer(DeserializerProtocol* deserializer) {
	assert(deserializer);
	this->deserializer = deserializer;
}

DeserializerProtocol* TcpServer::getDeserializer() {
	return deserializer;
}

void TcpServer::setSerializer(SerializerProtocol* serializer) {
	assert(serializer);
	this->serializer = serializer;
}

SerializerProtocol* TcpServer::getSerializer() {
	return serializer;
}

Session* TcpServer::getSession(std::string ip) {
	return manager->getSession(ip);
}

bool TcpServer::cutSession(std::string ip) {
	return manager->getSession(ip)->close();
}

SessionManager* TcpServer::getManager() const {
	return manager;
}

bool TcpServer::start() {
	assert (handler);
	started = serverSocket->listen();
	if (started) {
		ListenerThread* thread = new ListenerThread(this); // start socket listener
		thread->start();

		// start sender thread
		senderThread->start();
	}
	return started;
}

PojoSenderThread* TcpServer::getSenderThread() {
	return senderThread;
}

 /* namespace wanaka */
}
