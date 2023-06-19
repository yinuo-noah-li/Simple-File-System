#include "RenameParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
	string existing_file = "";
	istringstream iss(s);
	iss >> existing_file;
	vector<string> result = {s, existing_file };
	
	return result;
}
