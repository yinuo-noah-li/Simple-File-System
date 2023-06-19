// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <vector>
#include <iostream>
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\AbstractFileFactory.h"

int main()
{
	AbstractFileSystem* fileSystemPtr = new SimpleFileSystem();
	AbstractFileFactory* fileFactoryPtr = new SimpleFileFactory();

	//add file
	fileSystemPtr->addFile("test1.img", fileFactoryPtr->createFile("test1.img"));
	//open file
	AbstractFile* image = fileSystemPtr->openFile("test1.img");

	vector<char> testCase;
	testCase.push_back('X');
	testCase.push_back(' ');
	testCase.push_back('X');
	testCase.push_back(' ');
	testCase.push_back('X');
	testCase.push_back(' ');
	testCase.push_back('X');
	testCase.push_back(' ');
	testCase.push_back('X');
	testCase.push_back('3');
	//write and read
	image->write(testCase);
	image->read();
	return 0;
}
