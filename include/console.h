/*
 * console.h
 *
 *  Created on: Nov 14, 2017
 *      Author: efarhan
 */

#ifndef INCLUDE_CONSOLE_H_
#define INCLUDE_CONSOLE_H_

#include "imgui.h"
#include <vector>
#include <string>

class Console
{
public:
	void Draw();
	void AddLog(std::string log);
private:
	std::vector<std::string> log_texts;
};



#endif /* INCLUDE_CONSOLE_H_ */
