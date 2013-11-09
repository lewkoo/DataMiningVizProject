#pragma once

#include "Itemset.h"
using namespace std;

class Level
{

private:

	std::vector<Itemset> itemsets;

public:
	Level(void);
	~Level(void);
};

