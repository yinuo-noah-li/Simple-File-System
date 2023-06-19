// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

int main()
{
// Studio21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/AbstractFile.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/TouchCommand.h"
#include <iostream>
using namespace std;

int main()
{
	SimpleFileFactory* file_fac_ptr = new SimpleFileFactory();
	SimpleFileSystem* file_sys_ptr = new SimpleFileSystem();
	TouchCommand* touch_cmd = new TouchCommand(file_sys_ptr, file_fac_ptr);
	CommandPrompt* cmd_prompt = new CommandPrompt();

	cmd_prompt->setFileFactory(file_fac_ptr);
	cmd_prompt->setFileSystem(file_sys_ptr);
	cmd_prompt->addCommand("touch", touch_cmd);
	cmd_prompt->run();

	AbstractFile* fileP = file_sys_ptr->openFile("example_file.txt");
	if (fileP != nullptr) {
		return 0;
	}
	else {
		cout << "not good" << endl;
		return 1;
	}
	
	return 0;
}



