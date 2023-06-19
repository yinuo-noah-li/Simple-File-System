#include "TouchCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"
using namespace std;

#include <iostream>
#include <sstream>

TouchCommand::TouchCommand(AbstractFileSystem* abs_sys_ptr, AbstractFileFactory* abs_fac_ptr) :abs_sys_ptr(abs_sys_ptr), abs_fac_ptr(abs_fac_ptr) {
};

void TouchCommand::displayInfo() {

	cout << "The command 'touch' creates a file and can be invoked with the command : touch <filename>" << endl;

}

int TouchCommand::execute(string commandline) {
	if (commandline == "") {
		return wrongCommand;
	}
	//if there is no space
	if (commandline.find(" ") == negative_one) {
		AbstractFile* filePtr = abs_fac_ptr->createFile(commandline);
		if (filePtr != nullptr) {
			if (abs_sys_ptr->addFile(commandline, filePtr) == success) {
				return success;
			}
			else {
				delete abs_fac_ptr;
				return filefailtocreate;
			}
		}
		else {
			return filefailtocreate;
		}
	}
	//check if there is -p option
	else {
		string filename = "";
		string pwdOption = "";
		istringstream iss = istringstream(commandline);
		iss >> filename;
		AbstractFile* file = abs_fac_ptr->createFile(filename);
		if (file != nullptr) {
			iss >> pwdOption;
			if (pwdOption == "-p") {
				string password;
				cout << "Input your password: " << endl;
				getline(cin, password);
				AbstractFile* pwd_ptr = new PasswordProxy(file, password);
				if (abs_sys_ptr->addFile(filename, pwd_ptr) == success) {
					return success;
				}
				else {

					cout << "Failed To Create File" << endl;

					delete file;
					file = nullptr;

					return filefailtocreate;
				}
			}
			else {
				return wrongCommand;
			}
		}
		else {
			return filefailtocreate;
		}
	}
	
	return success;
}
