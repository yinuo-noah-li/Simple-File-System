#pragma once
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

#include <iostream>
#include <string>
#include <vector>
class AbstractFileVisitor;

class AbstractFile
{
public:
	virtual unsigned int getSize() = 0;
	virtual std::string getName() = 0;
	virtual int write(std::vector<char> v) = 0;
	virtual int append(std::vector<char> v) = 0;
	virtual std::vector<char> read() = 0;
	virtual void accept(AbstractFileVisitor* visitor_ptr) = 0;
	virtual AbstractFile* clone(std::string) = 0;
};
