// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <fstream>

using namespace std;

int SimpleFileSystem::addFile(string fileName, AbstractFile* abstractFile)
{
	/*if (files.find(fileName) == files.end()) {
		if (abstractFile != nullptr) {
			files.insert(make_pair(fileName, abstractFile));
			return success;
		}
		else {
			return failToOpen;
		}
	}*/
	auto fn = files.find(fileName);
	if (fn == files.end()) {
		if (abstractFile != nullptr) {
			files.insert(pair<string, AbstractFile*>(fileName, abstractFile));
			return success;
		}
		else if (abstractFile == nullptr) {
			return already_exist;
		}
	}
	else {
		return already_exist;
	}
	/*for (auto it = files.begin(); it != files.end(); ++it) {
		if (it->first == fileName) {
			return already_exist;
		}
	}
	if (abstractFile != nullptr) {
		files.insert(pair<string, AbstractFile*>(fileName, abstractFile));
		return success;
	}
	else {
		return already_exist;
	}*/

	return success;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> file_names;

	for (auto it = files.begin(); it != files.end(); it++)
	{
		file_names.insert(it->first);
	}
	return file_names;
}


AbstractFile* SimpleFileSystem::openFile(string fileName)
{
	if (files.find(fileName) == files.end())
	{
		return nullptr;
	}
	else {
		AbstractFile* abf = files.find(fileName)->second;
		if (openFiles.find(abf) == openFiles.end())
		{
			openFiles.insert(abf);
			return abf;
		}
		else {
			return nullptr;
		}
	}
	return nullptr;

}

int SimpleFileSystem::closeFile(AbstractFile* abstractFile)
{
	if (openFiles.find(abstractFile) == openFiles.end())
	{
		return failToOpen;
	}
	else {
		openFiles.erase(abstractFile);
		return success;
	}

	return success;
}

int SimpleFileSystem::deleteFile(string fileName)
{
	if (files.find(fileName) == files.end())
	{
		return failToOpen;
	}
	else
	{
		AbstractFile* abf = files.find(fileName)->second;
		if (openFiles.find(abf) == openFiles.end())
		{
			files.erase(fileName);
			delete abf;
			abf = nullptr;
			return success;
		}
		else {
			return failToOpen;
		}
	}
	return failToDelete; //file does not exist and can't be deleted

}
