/*
 * PojoTransferBean.h
 *
 *  Created on: 2014-11-27
 *      Author: Chris
 */

#ifndef POJOTRANSFERBEAN_H_
#define POJOTRANSFERBEAN_H_

namespace wanaka {

class Session;
class PojoProtocol;

class PojoTransferBean {
public:
	PojoTransferBean(PojoProtocol * pojo, Session * sesson);
	virtual ~PojoTransferBean();

	PojoProtocol* getPojo() const;
	Session* getSession() const;
private:
	PojoProtocol * pojo;
	Session * sesson;
};

} /* namespace wanaka */
#endif /* POJOTRANSFERBEAN_H_ */
