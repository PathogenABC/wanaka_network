/*
 * ServerSocket.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_

#include "Macro.h"

namespace wanaka {

class Socket;

class ServerSocket {
public:
	ServerSocket(int port);
	virtual ~ServerSocket();

	bool listen();
	Socket * accept();
private:
	bool bind();
private:
	struct sockaddr_in m_server_addr;
	SOCKET m_ssocket;
	int m_port;
	bool m_ssockActive;		// server socket is active?
};

} /* namespace wanaka */
#endif /* SERVERSOCKET_H_ */
