#ifndef PRINT_COMMAND_H
#define PRINT_COMMAND_H

#include "Command.h"
#include <string>
#include <iostream>

using namespace std;

class PrintCommand : public Command {
public:
	PrintCommand();
	PrintCommand(const string& payload);
	virtual ~PrintCommand();
	virtual void execute();	
private:
	string payload;
};

#endif
