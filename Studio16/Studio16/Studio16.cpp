// Studio16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "..\..\\SharedCode\TextFile.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[])
{
	AbstractFile* file = new TextFile("file.txt");
	vector<char> vc = { 'r', 'a', 'n', 'd', 'o', 'm' };
	vector<char> vc2 = {'s', 't', 'r'};
	file->write(vc);
	file->read();
	file->append(vc2);
	file->read();
	return 0;
}


