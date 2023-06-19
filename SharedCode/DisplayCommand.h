//Display Command.h
//name: Noah Li, Yujune Park, Chan Lee
//email: l.yinuo@wustl.edu, yujune.park@wustl.edu, chanl1@wustl.edu
//wustl ID: 502851, 487882, 457678
//Display command header

#pragma once
#include <iostream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand
{
public:
	DisplayCommand(AbstractFileSystem*);
	virtual int execute(std::string);
	virtual void displayInfo();
private:
	AbstractFileSystem* sys_ptr;
};
