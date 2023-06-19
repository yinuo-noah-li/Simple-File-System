#include "CatCommand.h"
#include "SimpleFileSystem.h"
#include <string>
#include <set>
#include <iomanip>
#include "MetadataDisplayVisitor.h"
#include <sstream>

using namespace std;

CatCommand::CatCommand(AbstractFileSystem* afs_sys_ptr) : afs_ptr(afs_sys_ptr){};

int CatCommand::execute(string commandline) {
	if (commandline.length() <= zero) {
		cout << "Incorrect Command" << endl;
		return wrongCommand;
	}
	//no space in command
	if (commandline.find(" ") == negative_one) {
		cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving the file." << endl;
		string filename = "";
		string given_input = "";
		size_t pos = commandline.find(".");
		string file_type = commandline.substr(pos);

		istringstream iss = istringstream(commandline);
		if (iss >> filename) 
		{
			AbstractFile* target_file = afs_ptr->openFile(filename);
			vector<char> input_vec;
			if (target_file == nullptr) {
				cout << "Such file does not exist" << endl;
				return failToOpen;
			}
			else {
				while (getline(cin, given_input)) 
				{
					//save the file by writing on the file and close it
					if (given_input == ":wq") 
					{
						input_vec.pop_back();
						if (target_file->write(input_vec) == success) {
							input_vec.clear();
							afs_ptr->closeFile(target_file);
							return success;
						}
						else {
							afs_ptr->closeFile(target_file);
							cout << "Failed to save" << endl;
							return failToWrite;
						}
					}
					//close file
					else if (given_input == ":q")
					{
						afs_ptr->closeFile(target_file);
						return success;
					}
					else 
					{
						//save the content into vector by iterating through
						for (auto it = given_input.begin(); it < given_input.end(); it++) {
							input_vec.push_back(*it);
						}
						input_vec.push_back('\n');

					}
				}
			}
		}
		else {
			return failToOpen;
		}
	
	}
	else {
		string filename = "";
		string option = "";
		istringstream iss = istringstream(commandline);

		if (iss >> filename && iss >> option) {
			if (option == "-a") {
				AbstractFile* target_file = afs_ptr->openFile(filename);
				if (target_file == nullptr) {
					return failToOpen;
				}
				else {
					vector<char> original_content = target_file->read();

					for (int i = 0; i < original_content.size(); ++i) {
						cout << original_content[i];
					}
					cout << endl;
					cout << "Enter data you would like to write to the file. Enter :wq to save the file and exit, enter :q to exit without saving the file." << endl;
					string given_input = "";
					vector<char> input_vec;
					while (getline(cin, given_input))
					{
						//save the file by writing on the file and close it
						if (given_input == ":wq")
						{
							input_vec.pop_back();
							if (target_file->append(input_vec) == success) {
								afs_ptr->closeFile(target_file);
								return success;
							}
							else {
								return failToWrite;
							}
						}
						//close file
						else if (given_input == ":q")
						{
							afs_ptr->closeFile(target_file);
							return success;
						}
						else
						{
							//save the content into vector by iterating through
							for (auto it = given_input.begin(); it < given_input.end(); it++) {
								input_vec.push_back(*it);
							}
							input_vec.push_back('\n');
						}
					}

				}
			}
			else {
				displayInfo();
				return wrongCommand;
			}
		}
		else {
			return wrongCommand;
		}
	}
	return success;
};

void CatCommand::displayInfo() {
	cout << "The CatCommand is invoked by 'cat <filename> [-a]' command. It overwrites the content of the file with the given input when -a is not given." << endl;
	cout << "If [-a] is given, then the file appends the given input." << endl;
}
