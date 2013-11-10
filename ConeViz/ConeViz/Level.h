#pragma once

#include "Itemset.h"
using namespace std;

class Level
{

private:

	static int levelNextId;
	int getNextId() { return ++levelNextId; }

	int levelId;
	std::vector<Itemset> itemsets;

public:
	Level(void);
	~Level(void);
};

