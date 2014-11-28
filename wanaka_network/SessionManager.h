/*
 * SessionManager.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SESSIONMANAGER_H_
#define SESSIONMANAGER_H_

#include <map>
#include <string>

namespace wanaka {

class Session;

class SessionManager {
public:
	SessionManager();
	virtual ~SessionManager();
public:
	Session* getSession(std::string ip);
	void putSession(Session *session);
private:
	std::map<std::string, Session *> sessions;
};

} /* namespace wanaka */
#endif /* SESSIONMANAGER_H_ */
