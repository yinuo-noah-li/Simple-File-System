#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include <vector>
class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};
