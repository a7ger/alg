#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <string>
#include "Token.h"
#include <vector>
#include "TokenType.h"

using namespace std;

class Lexer {
public:
	Lexer() : size(0), index(0) {}
	Lexer(const string& fileString) : fileString(fileString), size(fileString.length()), index(0) {}
	~Lexer(){}
	vector<Token>& tokenize(){
		while(index < size) {
			char c = fileString[index++];
			if (isalnum(c)) {
				getWord(c);
			} else {
				switch(c) {
				case '(' : tokens.push_back(Token(TokenType::LEFT_PAREN)); break;
				case ')' : tokens.push_back(Token(TokenType::RIGHT_PAREN)); break;
				case '\"' : extractStringLiteral(); break;
				case '\n': break;
				default : tokens.push_back(Token(TokenType::INVALID));
				}
			}
		}
		return tokens;
	}
	
private:
	
	char& getChar() {
		return fileString[index++];	
	}

	char& peekChar() {
		return fileString[index];
	}

	void getWord(const char& firstChar) {
		string word;
		word += firstChar;
		while(index < size) {
			if (isalnum(peekChar())) {
				word += getChar();
			} else {
				break;
			}
		}
		tokens.push_back(Token(TokenType::PRINT, word));
	}

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
		tokens.push_back(Token(TokenType::STRING_LITERAL, value));
	}

	string fileString;
	vector<Token> tokens;
	size_t size;
	size_t index;
};

#endif
