#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* sys_file_ptr;

public:
	CopyCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
};
