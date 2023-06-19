//  Define the TextFile class here

#include "TextFile.h"
#include "SimpleFileSystem.h"
using namespace std;

TextFile::TextFile(string name) : name(name) {
	size = 0;
}

unsigned int TextFile::getSize()
{
	return (unsigned int)contents.size();
}

AbstractFile* TextFile::clone(string s) {
	TextFile* cp_txt_file = new TextFile(*this);
	cp_txt_file->name = s;
	return cp_txt_file;
}

string TextFile::getName()
{
	return name;
}

int TextFile::write(vector<char> v)
{
	contents = v;
	return success;
}

int TextFile::append(vector<char> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		contents.push_back(v[i]);
	}
	return success;
}

vector<char> TextFile::read()
{
	return contents;
}


void TextFile::accept(AbstractFileVisitor* visitor_ptr)
{
	if (visitor_ptr)
	{
		visitor_ptr->visit_TextFile(this);
	}
}
