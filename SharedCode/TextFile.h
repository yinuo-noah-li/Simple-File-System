#pragma once
// TextFile declaration goes here

#include "AbstractFile.h"
#include "AbstractFileVisitor.h"

class TextFile : public AbstractFile
{

public:
	TextFile(std::string);
	virtual unsigned int getSize();
	virtual std::string getName();
	virtual int write(std::vector<char>);
	virtual int append(std::vector<char>);
	virtual std::vector<char> read();
	virtual void accept(AbstractFileVisitor* visitor_ptr);
	virtual AbstractFile* clone(std::string);

private:
	std::vector<char> contents;
	std::string name;
	int size;
};
