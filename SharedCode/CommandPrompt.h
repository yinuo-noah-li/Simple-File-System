#pragma once
#include <map>
#include <string>
#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
class CommandPrompt {
private:
	std::map<std::string, AbstractCommand*> abs_commands;
	AbstractFileFactory* file_fac_ptr;
	AbstractFileSystem* file_sys_ptr;

public:
	virtual ~CommandPrompt() = default;
	virtual void setFileSystem(AbstractFileSystem*);
	virtual void setFileFactory(AbstractFileFactory*);
	virtual int addCommand(std::string, AbstractCommand*);
	virtual int run();
	CommandPrompt();

	/*std::map<std::string, AbstractCommand*> abs_commands;
	AbstractFileFactory* file_fac_ptr;
	AbstractFileSystem* file_sys_ptr;*/


protected:
	void listCommands();
	std::string prompt();



};
