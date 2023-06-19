// Studio19.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
using namespace std;
#include <vector>
#include <iostream>
#include "..\..\SharedCode\SimpleFileFactory.h"
#include "..\..\SharedCode\SimpleFileSystem.h"
#include "..\..\SharedCode\AbstractFileFactory.h"
#include "..\..\SharedCode\BasicDisplayVisitor.h"
#include "..\..\SharedCode\AbstractFileVisitor.h"


int main()
{
	AbstractFileSystem* sysPtr = new SimpleFileSystem();
	AbstractFileFactory* facPtr = new SimpleFileFactory();
	sysPtr->addFile("test2.txt", facPtr->createFile("test2.txt"));
	AbstractFile* text = sysPtr->openFile("test2.txt");
	
	cout << text << endl;
	vector<char> text_content;
	text_content.push_back('a');
	text_content.push_back('b');
	text_content.push_back('c');
	text_content.push_back('d');

	text->write(text_content);
	vector<char> vec = text->read();
	//print first time
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i];
	}
	cout << endl;
	
	//rewrite
	text_content.push_back('e');
	text->write(text_content);
	vec = text->read();

	//reprint
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i];
	}
	cout << endl;

	return 0;
}
