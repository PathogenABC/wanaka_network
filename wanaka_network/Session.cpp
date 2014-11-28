/*
 * Session.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "Session.h"
#include "TerminalProtocol.h"
#include "PojoTransferBean.h"
#include "PojoProtocol.h"
#include "Socket.h"
#include "PojoSenderThread.h"
#include "Value.h"

namespace wanaka {

Session::Session(TerminalProtocol *terminal, Socket* socket) {
	this->terminal = terminal;
	this->socket = socket;
}

Session::~Session() {
}

void Session::writeAsyn(PojoProtocol* object) {
	PojoTransferBean *bean = new PojoTransferBean(object, this);
	terminal->getSenderThread()->pushBean(bean);
}

void Session::writeSyn(PojoProtocol* object) {

}

bool Session::start() {
	if (!socket->isConnected()) {
		return socket->connect();
	}
	return true;
}

bool Session::close() {
	socket->shut();
	return true;
}

void Session::putAttribute(const std::string& key, Value value) {
	attributes[key] = value;
}

Value Session::getAttribute(const std::string& key) {
	if (attributes.find(key) != attributes.end()) {
		return attributes[key];
	}
	return Value();		// NONE
}

std::string Session::getRemoteIp() {
	return socket->getRemoteIp();
}

int Session::getRemotePort() {
	return socket->getRemotePort();
}

int Session::getLocalPort() {
	return socket->getLocalPort();
}

bool Session::isConnected() {
	return socket->isConnected();
}

} /* namespace wanaka */
