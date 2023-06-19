#pragma once
#include "AbstractCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"

class TouchCommand : public AbstractCommand {
private:
	AbstractFileFactory* abs_fac_ptr;
	AbstractFileSystem* abs_sys_ptr;

public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	//~TouchCommand() = default;
	virtual int execute(std::string commandInfo) override;
	virtual void displayInfo() override;

};
