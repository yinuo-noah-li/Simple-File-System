

#include "PasswordProxy.h"
#include "SimpleFileSystem.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* af_ptr, string password) : af_ptr(af_ptr), password(password) {
}

PasswordProxy::~PasswordProxy() {
	delete af_ptr;
}

AbstractFile* PasswordProxy::clone(string s) {
	AbstractFile* cp_file = new PasswordProxy(af_ptr->clone(s), password);
	return cp_file;
}

string PasswordProxy::passwordPrompt() {
	string password;
	cout << "Input your password: " << endl;
	getline(cin, password);

	return password;
}

bool PasswordProxy::checkPassword(string pwd) {
	if (pwd == password) {
		return true;
	}
	else {
		cout << "Password is incorrect. Please try again." << endl;
		return false;
	}
}

vector<char> PasswordProxy::read() {
	cout << "You're trying to read this file. \n" << endl;

	vector<char> emptyVec = {};
	string givenPwd = passwordPrompt();
	//password is correct
	if (checkPassword(givenPwd)) {
		return af_ptr->read();
	}
	//password is wrong
	else {
		return emptyVec;
	}
}

int PasswordProxy::write(vector<char> v) {

	cout << "You're trying to write this file. \n" << endl;
	string givenPwd = passwordPrompt();
	if (checkPassword(givenPwd)) {
		return af_ptr->write(v);
	}
	else {
		return failToWrite;
	}
}

int PasswordProxy::append(vector<char> v) {

	cout << "You're trying to append this file" << endl;
	string givenPwd = passwordPrompt();
	if (checkPassword(givenPwd)) {
		return af_ptr->append(v);
	}
	else {
		return 5;
	}
}

unsigned int PasswordProxy::getSize() {
	return af_ptr->getSize();
}

string PasswordProxy::getName() {
	return af_ptr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor_ptr) {

	cout << "You're trying to accept this file." << endl;
	string givenPwd = passwordPrompt();
	if (checkPassword(givenPwd)) {
		af_ptr->accept(visitor_ptr);
	}

}


