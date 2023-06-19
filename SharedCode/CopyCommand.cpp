#include "CopyCommand.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"

using namespace std;

class AbstractFileSystem;

CopyCommand::CopyCommand(AbstractFileSystem* sys_file_ptr) :sys_file_ptr(sys_file_ptr) {
};

int CopyCommand::execute(string given_input) {
    if (given_input == "") {
        return wrongCommand;
    }
    istringstream iss = istringstream(given_input);

    string copied_file = "";
    string new_file = "";

    if (!(iss >> copied_file)) {
        displayInfo();
        return wrongCommand;
    }
    if (!(iss >> new_file)) {
        displayInfo();
        return wrongCommand;
    }

    if (iss >> copied_file) {
        displayInfo();
        return wrongCommand;
    }

    set<string> all_files = sys_file_ptr->getFileNames();
    string file_type = copied_file.substr(copied_file.find('.') + one);
    if (file_type == "img") {
        new_file = new_file + ".img";
    }
    else if (file_type == "txt") {
        new_file = new_file + ".txt";
    }
    else {
        return wrongCommand;
    }
    for (auto it = all_files.find(new_file); it != all_files.end(); ++it) {
        cout << "Copy failed. File already exists" << endl;
        return already_exist;
    }

    for (auto it = all_files.find(copied_file); it != all_files.end(); ++it) {
        AbstractFile* file = sys_file_ptr->openFile(copied_file);
        AbstractFile* clone_file = file->clone(new_file);
        if (file == nullptr || clone_file == nullptr) {
            sys_file_ptr->closeFile(file);
            sys_file_ptr->closeFile(clone_file);
            delete clone_file;
            return failToOpen;
        }
        int addResult = sys_file_ptr->addFile(new_file, clone_file);
        if (addResult != success) {
            sys_file_ptr->closeFile(file);
            sys_file_ptr->closeFile(clone_file);
            delete clone_file;
            return failToOpen;
        }
        sys_file_ptr->closeFile(file);
        sys_file_ptr->closeFile(clone_file);
        return success;
    }


    return failToOpen;
}

void CopyCommand::displayInfo() {
    cout << "The command 'cp' will the copy the content of one file and paste the content on the new file. This command can be invoked with cp <filename> <new_name_without_extension>" << endl;
};
