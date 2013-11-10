#pragma once

#include "Level.h"
#include "Itemset.h"

#include <iostream>
#include <sstream>
#include <direct.h>

using namespace std;

class Utilities
{
public:

	static void generateRandomItemsets(std::vector<Itemset>* itemsets); //TODO: add number of elements
	static void loadItemsets(char* fileName, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels);

	Utilities(void);
	~Utilities(void);
};

