#ifndef ARG_CHECKER_H
#define ARG_CHECKER_H

#include <iostream>
#include <fstream>
#include <string>

const string EXTENSION = "alg";

class ArgChecker {
public:
	ArgChecker(){}
	~ArgChecker(){}

	void checkArgs(const int& argc, const char** argv) {
		checkArgc(argc);
		string filename = argv[1];
		checkFileExtenstion(filename);
		checkFileExistance(filename);
	}

private:

	void checkFileExistance(const string& filename) {
		ifstream ifs(filename);
		if (ifs.fail()) {
			cout << "please provide a valid filename. \"" << filename << "\" not found." << endl;
			exit(1);
		} else {
			ifs.close();
		}
	}

	void checkArgc(const int& argc) {
		if (argc != 2) {
			cout << "please provide a single argument, the name of the file to compile." << endl;
			exit(1);
		}	
	}

	void checkFileExtenstion(const string& filename) {
		string extension;
		string chunk;
		size_t size = filename.length();
		for (size_t i = 0; i < size; ++i) {
			char c = filename[i];
			if (c != '.') {
				chunk += c;
				if (i == size - 1) {
					extension = chunk;
					break;	
				}
				
			} else {
				extension = chunk;
				chunk = "";
			}
		}
		if (extension != EXTENSION) {
			cout << "invalid extension: " << extension << ". Please provide a \"." << EXTENSION << "\" file." << endl;
			exit(1);
		}
	}
};


#endif
