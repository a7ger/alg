#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Lexer.h"
#include "Token.h"
#include "ArgChecker.h"

using namespace std;

string& fileToString(const string& filename) {
	static string result;
	ifstream ifs(filename);
	char c = 0;
	while ((c = ifs.get()) && c != EOF) {
		result += c;
	}
	return result;
}

int main(const int argc, const char** argv) {
	ArgChecker().checkArgs(argc, argv);
	Lexer lexer(fileToString(argv[1]));
	vector<Token> tokens = lexer.tokenize();
	for (auto token : tokens) {
		cout << token.toString() << endl;
	}
}
