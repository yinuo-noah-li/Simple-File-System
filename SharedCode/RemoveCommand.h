#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>
class RemoveCommand : public AbstractCommand {
public: 
	RemoveCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
	
private:
	AbstractFileSystem* afs_ptr;
};
