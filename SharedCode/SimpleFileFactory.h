#pragma once
// Studio 18 - simplefilefactory class declaration goes here

#include "AbstractFileFactory.h"
#include <map>
#include <string>

enum {
	ext_len = 3,
	inc = 1
};

class SimpleFileFactory : public AbstractFileFactory {
public:
	SimpleFileFactory();
	virtual AbstractFile* createFile(std::string);
private:
	std::map<std::string, AbstractFile*> files;
};
