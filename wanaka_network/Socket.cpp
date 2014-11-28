/*
 * Socket.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "Socket.h"

namespace wanaka {

Socket::Socket() {
	m_sockActive = false;
	m_connected = false;
	m_localIp = "";
	m_localPort = -1;
	m_remoteIp = "";
	m_remotePort = 0;
}

Socket::Socket(std::string ip, int port) :
		m_connected(false), m_localIp(""), m_localPort(-1), m_remoteIp(""), m_remotePort(0), m_sockActive(false) {
	m_remoteIp = ip;
	m_remotePort = port;
	m_addr_v4.sin_len = sizeof(struct sockaddr_in);
	m_addr_v4.sin_family = AF_INET;
	m_addr_v4.sin_port = htons(m_remotePort);
	m_addr_v4.sin_addr.s_addr = inet_addr(m_remoteIp.c_str()); // ip
	bzero(&(m_addr_v4.sin_zero), 8);
	m_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_socket == INVALID_SOCKET) {
		printf("initial socket error");
		m_sockActive = false;
	} else {
		m_sockActive = true;
		socklen_t addr_len = sizeof(m_addr_v4);
		if (0 == getsockname(m_socket, (struct sockaddr*) &m_addr_v4, &addr_len)) {
			m_localIp = inet_ntoa(m_addr_v4.sin_addr); // ip
			m_localPort = ntohs(m_addr_v4.sin_port); // port
		}
	}
}

Socket::~Socket() {
}

bool Socket::connect() {
	if (m_sockActive) {
		// connect 成功之后，其实系统将你创建的socket绑定到一个系统分配的端口上，且其为全相关，包含服务器端的信息，可以用来和服务器端进行通信。
		extern int connect(int, const struct sockaddr *, socklen_t) __DARWIN_ALIAS_C(connect); // declare
		if (connect(m_socket, (struct sockaddr *) &m_addr_v4, sizeof(struct sockaddr_in)) == 0) {
			m_connected = true;
		} else
			m_connected = false;
	}
	return m_connected;
}

bool Socket::isConnected() {
	return m_connected;
}

void Socket::shut() {
#ifdef WIN32
	closesocket(m_socket);
#else
	close(m_socket);
#endif
}

int Socket::read(char* buf, long len) {
	return recv(m_socket, buf, len, 0);
}

int Socket::write(const char* buf, int len) {
	return send(m_socket, buf, len, 0);
}

std::string Socket::getRemoteIp() {
	return m_remoteIp;
}

int Socket::getRemotePort() {
	return m_remotePort;
}

std::string Socket::getLocalIp() {
	return m_localIp;
}

int Socket::getLocalPort() {
	return m_localPort;
}

void Socket::localIpAndPort(SOCKET sock, std::string& localIp, int& localPort) {
	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	if (0 == getsockname(sock, (struct sockaddr*) &addr, &addr_len)) {
		localIp = inet_ntoa(addr.sin_addr); // ip
		localPort = ntohs(addr.sin_port); // port
	}
}

void Socket::remoteIpAndPort(SOCKET sock, std::string& remoteIp, int& remotePort) {
	struct sockaddr_in addr;
	socklen_t addr_len = sizeof(addr);
	if (0 == getpeername(sock, (struct sockaddr*) &addr, &addr_len)) {
		remoteIp = inet_ntoa(addr.sin_addr); // ip
		remotePort = ntohs(addr.sin_port); // port
	}
}

/* namespace wanaka */
}

