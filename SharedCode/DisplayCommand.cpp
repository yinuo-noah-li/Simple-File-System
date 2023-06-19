//DisplayCommand.cpp
//name: Noah Li, Yujune Park, Chan Lee
//email: l.yinuo@wustl.edu, yujune.park@wustl.edu, chanl1@wustl.edu
//wustl ID: 502851, 487882, 457678
//Display command source file

#include "DisplayCommand.h"
#include "SimpleFileSystem.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* system_ptr) : sys_ptr(system_ptr) {};

void DisplayCommand::displayInfo()
{
    cout << "Display is invoked with 'ds'" << " Display opens a file and displays its contents" << endl;
    cout << "When users only want the data display option, the input should be <filename> -d" << endl;
}

int DisplayCommand::execute(string cmd)
{
    string file_name = "";
    string option = "";
    istringstream iss = istringstream(cmd);
    //if there is no space, then there is only one command line argument after ds (file name)
    if (cmd.find(" ") == negative_one)
    {
        if (iss >> file_name)
        {
            AbstractFile* file = sys_ptr->openFile(file_name);
            if (file == nullptr)
            {
                return failToOpen;
            }
            AbstractFileVisitor* display_visitor = new BasicDisplayVisitor();
            file->accept(display_visitor);
            delete display_visitor;
            sys_ptr->closeFile(file);
            return success;
        }
        else 
        {
            return wrongCommand;
        }
    }
    //if there is a space, then it is likely that the user want the data-only display option
    else
    {
        if (iss >> file_name && iss >> option)
        {
            if (option == "-d")
            {
                AbstractFile* file = sys_ptr->openFile(file_name);
                if (file == nullptr)
                {
                    return failToOpen;
                }

                vector<char> contents = file->read();
                for (int i = 0; i < contents.size(); ++i)
                {
                    cout << contents[i];
                }
                cout << endl;
                sys_ptr->closeFile(file);
                return success;
            }
            else
            {
                displayInfo();
                return wrongCommand;
            }
        }
        else {
            return wrongCommand;
        }
    }
}
