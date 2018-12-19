#include "Parser.h"
#include "PrintCommand.h"

Parser::Parser() : size(0), index(0) {}

Parser::~Parser(){}

Parser::Parser(const vector<Token>& tokens) : tokens(tokens), size(tokens.size()), index(0) {}

vector<Command*>& Parser::parse() {
	
	while(this->index < this->size) {
		Token t = tokens[this->index++];
		switch(t.type) {
		case TokenType::PRINT : extractPrintCommand(); break;
		case TokenType::LEFT_PAREN : break;
		case TokenType::RIGHT_PAREN : break;
		case TokenType::STRING_LITERAL : break;
		case TokenType::INVALID : break;
		}
	} 
	return commands;
}

void Parser::extractPrintCommand() {
	if (this->size - index < 3) {
		cout << "invalid print command" << endl;
		exit(1);
	}
	if (tokens[this->index++].type != TokenType::LEFT_PAREN) {
		cout << "expected left paren" << endl;
		exit(1);
	}
	if (tokens[this->index].type != TokenType::STRING_LITERAL) {
		cout << "expected string literal" << endl;
		exit(1);
	}
	string payload = tokens[index++].payload;
	if (tokens[this->index++].type != TokenType::RIGHT_PAREN) {
		cout << "expected right paren" << endl;
		exit(1);
	}
	commands.push_back(new PrintCommand(payload));
}
