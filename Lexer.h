#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <string>
#include "Token.h"
#include <vector>

using namespace std;

class Lexer {
public:
	Lexer() : size(0), index(0) {}
	Lexer(const string& fileString_) : fileString(fileString_), size(fileString.length()), index(0) {}
	~Lexer(){}
	vector<Token>& tokenize(){
		while(index < size) {
			char c = fileString[index++];
			switch(c) {
			case '\"' : extractStringLiteral(); break;
			case '\n': break;
			default : cout << "missed on: " << c << endl;
			}
		}
		return tokens;
	}
	
private:
	void extractStringLiteral() {
		string value;
		while(index < size) {
			char c = fileString[index++];
			if (c != '\"') {
				value += c;
			} else {
				break;
			}
		}
		tokens.push_back(Token(value));
	}

	string fileString;
	vector<Token> tokens;
	size_t size;
	size_t index;
};

#endif
