// definitions of basic display visitor here
#include "BasicDisplayVisitor.h"
#include <iostream>
#include "SimpleFileSystem.h"
using namespace std;


void BasicDisplayVisitor::visit_ImageFile(ImageFile* image)
{
	vector<char> contents = image->read();
	int size = (int) (sqrt(image->getSize()));
	for (int i = size - one; i >= 0; --i)
	{
		for (int j = 0; j < size; ++j)
		{
			int index = i * size + j;
			cout << contents[index];
		}
		cout << endl;
	}
}


void BasicDisplayVisitor::visit_TextFile(TextFile* text)
{
	vector<char> contents = text->read();
	for (int i = 0; i < contents.size(); ++i)
	{
		cout << contents[i];
	}
	cout << endl;
}
