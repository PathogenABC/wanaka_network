/*
 * Session.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SESSION_H_
#define SESSION_H_

#include <string>

#include "Value.h"

namespace wanaka {

class Value;
class PojoProtocol;
class Socket;
class TerminalProtocol;

class Session {
public:
	Session(TerminalProtocol *terminal, Socket *socket);
	virtual ~Session();
public:
	void writeAsyn(PojoProtocol *object);	//	异步
	void writeSyn(PojoProtocol *object);		//  同步

	bool start();
	bool close();

	void putAttribute(const std::string &key, Value value);
	Value getAttribute(const std::string &key);

	std::string getRemoteIp();
	int getRemotePort();
	int getLocalPort();

	bool isConnected();
private:
	Socket *socket;
	TerminalProtocol *terminal;
	wanaka::ValueDict attributes;
};

} /* namespace wanaka */
#endif /* SESSION_H_ */
