#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <vector>
#include "Token.h"
#include "Command.h"

using namespace std;

class Parser {
public:
	Parser(const vector<Token>&);
	Parser();
	~Parser();
	vector<Command*>& parse();
private:
	size_t size;
	size_t index;
	vector<Command*> commands;
	vector<Token> tokens;
	void extractPrintCommand();
};


#endif
