#include <iosfwd>
/*
 * ServerProtocol.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SERVERPROTOCOL_H_
#define SERVERPROTOCOL_H_

#include <string>
#include "TerminalProtocol.h"

namespace wanaka {

class SessionManager;
class Session;

class ServerProtocol : public TerminalProtocol {
public:
	virtual ~ServerProtocol();

	virtual SessionManager * getManager() const = 0;

	virtual Session * getSession(std::string ip) = 0;
	virtual bool cutSession(std::string ip) = 0; // remove session by the specified ip
	virtual bool isStarted() const = 0;
	virtual void setStarted(bool start) = 0;
};

} /* namespace wanaka */
#endif /* SERVERPROTOCOL_H_ */
