#include "SimpleFileSystem.h"
#include "LSCommand.h"
#include <string>
#include <set>
#include <iomanip>
#include "MetadataDisplayVisitor.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* sys_ptr) : afs_ptr(sys_ptr) {};

int LSCommand::execute(string input_str) {
	set<string> file_names = afs_ptr->getFileNames();

	//command is ls
	if (input_str == "") {
		int count = 1;
		for (auto it = file_names.begin(); it != file_names.end(); it++)
		{
			//we have 2 files in one line
			if (count % 2 == 0) {
				cout << setw(maxLen) << *it << endl;
			}
			else {
				cout << *it;
			}
			count++;
		}
		cout << endl;
	}
	else if(input_str == "-m")
	{
		AbstractFileVisitor* file_vis = new MetadataDisplayVisitor();
		for (auto it = file_names.begin(); it != file_names.end(); ++it)
		{
			AbstractFile* fileToBeOpened = afs_ptr->openFile(*it);
			fileToBeOpened->accept(file_vis);
			afs_ptr->closeFile(fileToBeOpened);
		}
	}
	else {
		displayInfo();
		return wrongCommand;
	}

	return success;
}


void LSCommand::displayInfo() {
	cout << "The LSCommand is invoked by 'ls' or 'ls -m' command, and it outputs all the filenames in current in the file system." << endl;
	cout << "the -m option displays the files with metadata." << endl;
}
