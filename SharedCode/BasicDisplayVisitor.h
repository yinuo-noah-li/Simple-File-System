#pragma once
// declaration of BasicDisplayVisitor here
#include "ImageFile.h"
#include "TextFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor
{
public:
    virtual void visit_ImageFile(ImageFile* image);
    virtual void visit_TextFile(TextFile* text);
};