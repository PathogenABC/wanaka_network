/*
 * Socket.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include <string>
#include "Macro.h"

namespace wanaka {

class Socket {
private:
	struct sockaddr_in m_addr_v4; // server address info structure
	SOCKET m_socket; // socket 句柄

	std::string m_remoteIp;
	int m_remotePort;
	std::string m_localIp;
	int m_localPort;

	bool m_connected;
	bool m_sockActive;
public:
	Socket(std::string ip, int port);
	Socket();
	virtual ~Socket();
public:
	bool connect();
	bool isConnected();
	void shut();	// close

	int read(char *buf, long len);
	int write(const char* buf, int len);

	std::string getRemoteIp();
	int getRemotePort();
	std::string getLocalIp();
	int getLocalPort();

	static void localIpAndPort(SOCKET sock, std::string &localIp, int &localPort);
	static void remoteIpAndPort(SOCKET sock, std::string &remoteIp, int &remotePort);

	friend class ServerSocket;
};

} /* namespace wanaka */
#endif /* SOCKET_H_ */
