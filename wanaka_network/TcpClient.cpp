/*
 * TcpClient.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "TcpClient.h"
#include <assert.h>
#include "Socket.h"
#include "Session.h"
#include "PojoSenderThread.h"
#include "HandlerProtocol.h"
#include "SessionThread.h"

namespace wanaka {

TcpClient::TcpClient(std::string ip, int port) : handler(NULL), deserializer(NULL), serializer(NULL) {
	Socket *sock = new Socket(ip, port);
	session = new Session(this, sock);
	senderThread = new PojoSenderThread(this);
}

TcpClient::~TcpClient() {

}

void TcpClient::setHandler(HandlerProtocol *handler) {
	assert(handler);
	this->handler = handler;
}

void TcpClient::setDeserializer(DeserializerProtocol *deserializer) {
	assert(deserializer);
	this->deserializer = deserializer;
}

void TcpClient::setSerializer(SerializerProtocol *serializer) {
	assert(serializer);
	this->serializer = serializer;
}

bool TcpClient::start() {
	assert(handler);
	bool started = session->start();
	if (started) {
		handler->sessionCreated(session);	// call back when session created

		// start a channel thread communication with the server
		SessionThread *channel = new SessionThread(this, session);
		channel->start();

		// start sender thread
		senderThread->start();
	}
	return started;
}

Session* TcpClient::getSession() {
	return session;
}

HandlerProtocol* TcpClient::getHandler() {
	return handler;
}

DeserializerProtocol* TcpClient::getDeserializer() {
	return deserializer;
}

SerializerProtocol* TcpClient::getSerializer() {
	return serializer;
}

bool TcpClient::isConnected() {
	return session->isConnected();
}

PojoSenderThread* TcpClient::getSenderThread() {
	return senderThread;
}

/* namespace wanaka */
}

