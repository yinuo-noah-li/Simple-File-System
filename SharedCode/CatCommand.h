#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"


class CatCommand : public AbstractCommand {
public:
	CatCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs_ptr;
};
