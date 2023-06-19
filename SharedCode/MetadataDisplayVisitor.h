#pragma once
#include "AbstractFileVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"


enum width_values {
    width_one = 15,
    width_two = 10
};

class MetadataDisplayVisitor : public AbstractFileVisitor {
    virtual void visit_ImageFile(ImageFile* image);
    virtual void visit_TextFile(TextFile* text);
};
