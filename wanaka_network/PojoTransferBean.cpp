/*
 * PojoTransferBean.cpp
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#include "PojoTransferBean.h"
#include "PojoProtocol.h"
#include "Session.h"

namespace wanaka {

PojoTransferBean::PojoTransferBean(PojoProtocol* pojo, Session* sesson) {
	this->pojo = pojo;
	this->sesson = sesson;
}

PojoTransferBean::~PojoTransferBean() {

}

PojoProtocol* PojoTransferBean::getPojo() const {
	return pojo;
}

Session* PojoTransferBean::getSession() const {
	return sesson;
}

} /* namespace wanaka */
