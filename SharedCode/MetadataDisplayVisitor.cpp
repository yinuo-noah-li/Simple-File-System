// definitions of metadata visitor here
#include "MetadataDisplayVisitor.h"
#include <iostream>
#include <iomanip>

using namespace std;

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* image)
{
	cout << image->getName() <<  "  " <<  "image " << image->getSize() << endl;;

}

void MetadataDisplayVisitor::visit_TextFile(TextFile* text)
{
	cout << text->getName() << "  " << "text " << text->getSize() << endl;
	
}
