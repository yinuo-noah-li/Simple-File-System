#pragma once
#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* file_ptr, std::string password);
	~PasswordProxy();

	 unsigned int getSize();
	 std::string getName();
	 int write(std::vector<char> v);
	 int append(std::vector<char> v);
	 std::vector<char> read();
	 void accept(AbstractFileVisitor* visitor_ptr);
	 virtual AbstractFile* clone(std::string);

protected:
	std::string passwordPrompt();
	bool checkPassword(std::string password);
private:
	AbstractFile* af_ptr;
	std::string password;
};
