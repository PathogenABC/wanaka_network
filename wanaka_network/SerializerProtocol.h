/*
 * SerializeProtocol.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef SERIALIZEPROTOCOL_H_
#define SERIALIZEPROTOCOL_H_

#include <vector>
#include "Macro.h"

namespace wanaka {

class PojoProtocol;

class SerializerProtocol {
public:
	virtual ~SerializerProtocol();

	virtual std::vector<byte> serialize(PojoProtocol *object) = 0;
};

} /* namespace wanaka */
#endif /* SERIALIZEPROTOCOL_H_ */
