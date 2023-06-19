// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/AbstractFileFactory.h"
#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/AbstractFileVisitor.h"
#include "../../SharedCode/AbstractParsingStrategy.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/ImageFile.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/TouchCommand.h"
#include "CatdsParsingStrategy.h"



int main()
{
	SimpleFileSystem* sys_file_ptr = new SimpleFileSystem();
	SimpleFileFactory* fac_file_ptr = new SimpleFileFactory();

	TouchCommand* touch_cmd = new TouchCommand(sys_file_ptr, fac_file_ptr);
	LSCommand* ls_cmd = new LSCommand(sys_file_ptr);
	RemoveCommand* rm_cmd = new RemoveCommand(sys_file_ptr);
	CatCommand* cat_cmd = new CatCommand(sys_file_ptr);
	CopyCommand* cp_cmd = new CopyCommand(sys_file_ptr); 
	DisplayCommand* ds_cmd = new DisplayCommand(sys_file_ptr);

	MacroCommand* rn_cmd = new MacroCommand(sys_file_ptr);
	RenameParsingStrategy* rps = new RenameParsingStrategy();
	rn_cmd->addCommand(cp_cmd);
	rn_cmd->addCommand(rm_cmd);
	rn_cmd->setParseStrategy(rps);
	
	MacroCommand* catds_cmd = new MacroCommand(sys_file_ptr);
	CatdsParsingStrategy* cps = new CatdsParsingStrategy();
	catds_cmd->addCommand(cat_cmd);
	catds_cmd->addCommand(ds_cmd);
	catds_cmd->setParseStrategy(cps);

	CommandPrompt cmd_prompt;
	cmd_prompt.setFileFactory(fac_file_ptr);
	cmd_prompt.setFileSystem(sys_file_ptr);
	cmd_prompt.addCommand("touch", touch_cmd);
	cmd_prompt.addCommand("ls", ls_cmd);
	cmd_prompt.addCommand("rm", rm_cmd);
	cmd_prompt.addCommand("cat", cat_cmd);
	cmd_prompt.addCommand("ds", ds_cmd);
	cmd_prompt.addCommand("cp", cp_cmd);
	cmd_prompt.addCommand("rn", rn_cmd);
	cmd_prompt.addCommand("catds", catds_cmd);

	cmd_prompt.run();

	return success;
}


