/*
 * Macro.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef MACRO_H_
#define MACRO_H_

#include <map>
#include <vector>

#ifdef WIN32
#include <winsock.h>
typedef unsigned int socklen_t;

#define close(sock) closesocket(sock)	// close method

#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
typedef int SOCKET;

//#pragma region define win32 const variable in linux
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
//#pragma endregion
#endif

namespace wanaka {

#include "Value.h"

typedef char byte;

}  // namespace wanakaS

#endif /* MACRO_H_ */
