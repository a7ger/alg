#include "Token.h"

Token::Token(){}

Token::~Token(){}

Token::Token(const TokenType& type) {
	this->type = type;
}

Token::Token(const TokenType& type, const string& payload) {
	this->type = type;
	this->payload = payload;
}
