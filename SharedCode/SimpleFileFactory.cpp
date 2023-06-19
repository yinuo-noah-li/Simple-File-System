// studio 18 - simple file factory definitions

#include "SimpleFileFactory.h"
#include "TextFile.h"
#include "ImageFile.h"

using namespace std;

SimpleFileFactory::SimpleFileFactory() {}

AbstractFile* SimpleFileFactory::createFile(std::string fileName)
{
	if (fileName.size() < ext_len)
	{
		return nullptr; //file exists
	}

	string extension = fileName.substr(fileName.find('.') + inc);
	//cout << extension << endl;
	if (extension == "txt")
	{
		TextFile* textfile = new TextFile(fileName);
		return textfile;
	}
	else if (extension == "img")
	{
		ImageFile* imagefile = new ImageFile(fileName);
		return imagefile;
	}

	return nullptr; //unrecognized file extension
}
