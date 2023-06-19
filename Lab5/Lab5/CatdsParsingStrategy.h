#pragma once
#include "../../SharedCode/AbstractCommand.h"
#include "../../SharedCode/AbstractParsingStrategy.h"
#include <vector>

class CatdsParsingStrategy : public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string);
};
