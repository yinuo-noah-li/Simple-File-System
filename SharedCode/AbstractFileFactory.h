#pragma once
// studio 18 - file factory interface declared here

#include "AbstractFileSystem.h"

class AbstractFileFactory {
public:
	AbstractFileFactory() = default;
	virtual AbstractFile* createFile(std::string) = 0;
};