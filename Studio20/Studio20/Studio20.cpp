// Studio20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/PasswordProxy.h"
#include <iostream>
#include <vector>
int main()
{
	AbstractFile* exampleFile = new TextFile("example1.txt");
	PasswordProxy pwd = PasswordProxy(exampleFile, "password");
	std::vector<char> vec;
	vec.push_back('a');
	vec.push_back('b');
	vec.push_back('c');
	for (size_t i = 0; i < vec.size(); ++i) {
		pwd.write(vec);
	}

	std::vector<char> res = pwd.read();

	for (size_t i = 0; i < res.size(); ++i) {
		std::cout << res[i];
	}
	std::cout << std::endl;

	delete exampleFile;

	return 0;
}

