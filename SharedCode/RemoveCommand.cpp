#include "RemoveCommand.h"
#include "SimpleFileSystem.h"
#include <string>
#include <iostream>
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* afs_ptr) : afs_ptr(afs_ptr) {  };

int RemoveCommand::execute(string filename) {
	if (afs_ptr->deleteFile(filename) == success) {
		return success;
	}
	else {
		return failToDelete;
	}
	return success;
}

void RemoveCommand::displayInfo() {
	cout << "The remove command should be invoked by the user with 'rm <filename>' which will remove the given file" << endl;
}
