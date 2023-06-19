#pragma once
#include "AbstractCommand.h"
#include <vector>
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
class MacroCommand : public AbstractCommand {
private:
	std::vector<AbstractCommand*> cmd_vec;
	AbstractParsingStrategy* cmd_parse_ptr;
	AbstractFileSystem* afs_ptr;

public:
	MacroCommand(AbstractFileSystem* );
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
	virtual int execute(std::string);
	virtual void displayInfo();
};
