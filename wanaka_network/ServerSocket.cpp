/*
 * ServerSocket.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */


#define LENGTH_OF_LISTEN_QUEUE 40

#include "ServerSocket.h"
#include "Socket.h"

namespace wanaka {

ServerSocket::ServerSocket(int port) :
		m_ssockActive(false), m_ssocket(INVALID_SOCKET) {
	m_port = port;
	bzero(&m_server_addr, sizeof(m_server_addr)); //把一段内存区的内容全部设置为0
	m_server_addr.sin_family = AF_INET;
	m_server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	m_server_addr.sin_port = htons(port);
	m_ssocket = socket(AF_INET, SOCK_STREAM, 0);
	if (m_ssocket == INVALID_SOCKET) {
		printf("initial socket error");
		m_ssockActive = false;
	} else {
		m_ssockActive = true;
		bind();
	}
}

ServerSocket::~ServerSocket() {
}

bool ServerSocket::listen() {
	extern int listen(int, int) __DARWIN_ALIAS(listen);
	return listen(m_ssocket, LENGTH_OF_LISTEN_QUEUE) != -1;
}

Socket* ServerSocket::accept() {
	extern int accept(int, struct sockaddr * __restrict, socklen_t * __restrict) __DARWIN_ALIAS_C(accept);
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	SOCKET clientHsock = accept(m_ssocket, (struct sockaddr*) ((&client_addr)), &len);
	Socket* sock = new Socket();
	sock->m_addr_v4 = client_addr;
	sock->m_socket = clientHsock;
	sock->m_connected = true;
	sock->m_sockActive = true;
	Socket::localIpAndPort(sock->m_socket, sock->m_localIp, sock->m_localPort);
	Socket::remoteIpAndPort(sock->m_socket, sock->m_remoteIp, sock->m_remotePort);
	return sock;
}

bool ServerSocket::bind() {
	extern int bind(int, const struct sockaddr *, socklen_t)
	__DARWIN_ALIAS(bind);
	return bind(m_ssocket, (struct sockaddr*) (&m_server_addr), sizeof(m_server_addr) != -1);
}

} /* namespace wanaka */
