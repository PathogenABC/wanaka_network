/*
 * ClientProtocol.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef CLIENTPROTOCOL_H_
#define CLIENTPROTOCOL_H_

#include "TerminalProtocol.h"

namespace wanaka {

class Session;

class ClientProtocol : public TerminalProtocol {
public:
	virtual ~ClientProtocol();

	virtual Session* getSession() = 0;
	virtual bool isConnected() = 0;
};

} /* namespace wanaka */
#endif /* CLIENTPROTOCOL_H_ */
