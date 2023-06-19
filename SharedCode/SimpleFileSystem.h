#pragma once
// declaration of SimpleFileSystem class goes here

#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include <map>
#include <set>

enum return_values {
	success,
	filefailtocreate,
	failToOpen,
	already_exist,
	userQuit,
	mapInsertionFail,
	wrongCommand,
	failToWrite,
	failToDelete,
	invalidSize
};

enum file_info {
	zero = 0,
	file_type_len = 3,
	one = 1,
	negative_one = -1,
	max_size = 48
};

class SimpleFileSystem : public AbstractFileSystem
{
public:
	virtual int addFile(std::string, AbstractFile*);
	virtual int deleteFile(std::string);
	virtual AbstractFile* openFile(std::string);
	virtual int closeFile(AbstractFile*);
	virtual std::set<std::string> getFileNames();
private:
	std::map<std::string, AbstractFile*> files;
	std::set<AbstractFile*> openFiles;
};
