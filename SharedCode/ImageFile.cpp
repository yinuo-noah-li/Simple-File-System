// definition of ImageFile class here

#include "ImageFile.h"
#include "SimpleFileSystem.h"
using namespace std;

ImageFile::ImageFile(string s) : name(s)
{
	size = 0;
}

AbstractFile* ImageFile::clone(string s) {
	ImageFile* cp_image_file = new ImageFile(*this);
	cp_image_file->name = s;
	return cp_image_file;
}

unsigned int ImageFile::getSize()
{
	return (unsigned int) contents.size();
}

string ImageFile::getName()
{
	return name;
}

int ImageFile::write(vector<char> v)
{
	size = v[v.size() - one] - max_size;
	for (int i = 0; i < v.size() - one; ++i)
	{
		contents.push_back(' ');
		contents[i] = v[i];
	}

	int num_elements = size * size;

	if (num_elements != (v.size() - one))
	{
		contents.clear();
		return invalidSize; //size mismatch
	}

	for (int i = 0; i < v.size() - 1; ++i)
	{
		if (v[i] != 'X' && v[i] != ' ')
		{
			contents.clear();
			return failToOpen; //pixel not valid
		}
	}

	return success;
}

int ImageFile::append(vector<char> v)
{
	return failToWrite;
}

vector<char> ImageFile::read()
{
	for (int y = size - one; y >= 0; --y)
	{
		for (int x = 0; x < size; ++x)
		{
			int index = y * size + x;
			//cout << contents[index];
		}
		//cout << endl;
	}

	return contents;
}


void ImageFile::accept(AbstractFileVisitor* visitor_ptr)
{
	if (visitor_ptr)
	{
		visitor_ptr->visit_ImageFile(this);
	}
}
