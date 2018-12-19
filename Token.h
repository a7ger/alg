#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "TokenType.h"


using namespace std;

class Token {
public:
	Token();
	Token(const TokenType&);
	Token(const TokenType&, const string&) ;
	~Token();
	string payload;
	TokenType type;
};

#endif
