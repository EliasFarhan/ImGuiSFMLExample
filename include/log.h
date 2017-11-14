/*
 * log.h
 *
 *  Created on: Nov 14, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_LOG_H_
#define INCLUDE_LOG_H_

#include <utility.h>
#include <string>

class Log : public Singleton<Log>
{
protected:
	using Singleton::Singleton;
public:
	void Msg(std::string msg);
	void Err(std::string err);

};


#endif /* INCLUDE_LOG_H_ */
