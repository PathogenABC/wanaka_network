/*
 * DeserializeProtocol.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef DESERIALIZEPROTOCOL_H_
#define DESERIALIZEPROTOCOL_H_

namespace wanaka {

class Session;
class PojoProtocol;

class DeserializerProtocol {
public:
	virtual ~DeserializerProtocol();

	// construct a pojo from a session
	virtual PojoProtocol * deserialize(const Session *session) = 0;	// io blocked method
};

} /* namespace wanaka */
#endif /* DESERIALIZEPROTOCOL_H_ */
