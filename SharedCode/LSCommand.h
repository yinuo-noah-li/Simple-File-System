#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"

enum {
	maxLen = 20
};

class LSCommand : public AbstractCommand
{
public:
	LSCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs_ptr;
};

