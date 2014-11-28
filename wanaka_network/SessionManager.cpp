/*
 * SessionManager.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "SessionManager.h"
#include "Session.h"

namespace wanaka {

SessionManager::SessionManager() {

}

SessionManager::~SessionManager() {
}

Session* SessionManager::getSession(std::string ip) {
	if (sessions.find(ip) != sessions.end()) {
		return sessions[ip];
	}
	return NULL;

}

void SessionManager::putSession(Session* session) {
	sessions[session->getRemoteIp()] = session;
}

 /* namespace wanaka */
}
