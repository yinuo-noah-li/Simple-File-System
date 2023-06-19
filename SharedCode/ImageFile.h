#pragma once
// Image file class declaration here

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"
class ImageFile : public AbstractFile
{
public:
	ImageFile(std::string s);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual std::vector<char> read();
	virtual void accept(AbstractFileVisitor* visitor_ptr);
	virtual AbstractFile* clone(std::string);

private:
	std::string name;
	std::vector<char> contents;
	char size;
};
