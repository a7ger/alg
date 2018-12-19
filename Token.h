#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

using namespace std;

class Token {
public:
	Token(){}
	Token(const string& value_) : value(value_) {}
	~Token(){}
	string& toString() {
		return value;
	}
private:
	string value;
};

#endif
