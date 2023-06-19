#include "MacroCommand.h"
#include "SimpleFileSystem.h"
using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs_sys_ptr) : afs_ptr(afs_sys_ptr), cmd_parse_ptr(nullptr), cmd_vec({}) {};

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_ptr) {
	cmd_parse_ptr = aps_ptr;
}

int MacroCommand::execute(string given_input) {
	vector<string> all_names = cmd_parse_ptr->parse(given_input);
	if (all_names.size() > zero)
	{
		int count = 0;
		for (auto it = cmd_vec.begin(); it < cmd_vec.end(); ++it)
		{
			AbstractCommand* abs_cmd = *it;
			if (abs_cmd->execute(all_names[count]) != success) {
				displayInfo();
				return wrongCommand;
			}
			
			count++;
		}
		return success;
	}
	else {
		displayInfo();
		return wrongCommand;
	}

}

void MacroCommand::displayInfo() {
	cout << "Rename can be invoked by the user with 'rn <filename> <new_name_with_no_extension>' and can rename the name of an original file. " << endl;
	cout << "Cat+Ds can be invoked by the user with 'catds <filename>' and can edit the content of and display the file as well. " << endl;

}

void MacroCommand::addCommand(AbstractCommand* command) {
	cmd_vec.push_back(command);

}
