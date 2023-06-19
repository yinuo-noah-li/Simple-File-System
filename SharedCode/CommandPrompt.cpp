#include "CommandPrompt.h"
#include "SimpleFileSystem.h"
#include "AbstractCommand.h"
#include <iostream>
#include <sstream>
using namespace std;

CommandPrompt::CommandPrompt() : file_fac_ptr(nullptr), file_sys_ptr(nullptr) {
};

void CommandPrompt::setFileSystem(AbstractFileSystem* file_system_ptr) {
	file_sys_ptr = file_system_ptr;
};

void CommandPrompt::setFileFactory(AbstractFileFactory* file_factory_ptr) {
	file_fac_ptr = file_factory_ptr;
};

int CommandPrompt::addCommand(std::string str_cmd, AbstractCommand* cmd) {
	if (abs_commands.insert(make_pair(str_cmd, cmd)).second)
	{
		return success;
	}
	else {
		cout << "insertion not successful" << endl;
		return mapInsertionFail;
	}
	return success;
}

void CommandPrompt::listCommands() {
	for (auto i : abs_commands) {
		cout << i.first << endl;
	}
}

string CommandPrompt::prompt() {
	cout << "Enter a command, q to quit, help for a list of commands, or help followed by a command name for more information about that command." << endl;
	cout << "$  ";
	string inputCmd;
	getline(cin, inputCmd);
	return inputCmd;
}

int CommandPrompt::run() {
	string tmp = "";
	while (1) {
		string input = prompt();
		if (input == "q") {
			return userQuit;
		}
		else if (input == "help") {
			listCommands();
		}
		else {
			//more than one word
			if (input.find(' ')) {
				istringstream iss = istringstream(input);
				string first_input = "";
				iss >> first_input;
				if (first_input == "help") {
					string second_input = "";
					iss >> second_input;
					if (abs_commands.find(second_input) != abs_commands.end()) {
						abs_commands.find(second_input)->second->displayInfo();
					}
					else {
						cout << "command failed" << endl;
					}
				}
				else {
					if (abs_commands.find(first_input) != abs_commands.end()) {
						string remainder = "";
						getline(iss, remainder);
						remainder.erase(zero, one);
						
						if (abs_commands.find(first_input)->second->execute(remainder) != success) {
							cout << "command failed1" << endl;
						}
					}
					else {
						cout << "command failed2" << endl;
					}
				}
			}
			//one word
			else {
				if (abs_commands.find(input) != abs_commands.end()) {
					int cmd_result = abs_commands.find(input)->second->execute("");
					if (cmd_result != success) 
					{
						cout << "command failed" << endl;
					}
				}
				else {
					cout << "command failed" << endl;
				}
			}
		}
	}
	return success;
}
