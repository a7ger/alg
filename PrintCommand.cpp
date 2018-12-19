#include "PrintCommand.h"

PrintCommand::PrintCommand(){}

PrintCommand::PrintCommand(const string& payload) : payload(payload) {}

PrintCommand::~PrintCommand(){}

void PrintCommand::execute() {
	cout << this->payload << endl;
	cout.flush();
}
