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

	static enum SHAPE_TYPES {FLAT_CONE, NORMAL_CONE, INVERTED_CONE};

	static void generateRandomItemsets(std::vector<Itemset>* itemsets); //TODO: add number of elements
	static void loadItemsets(char* fileName, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels);
	static void setYCoordinates(std::vector<Level*>* levels, SHAPE_TYPES newShape);


	Utilities(void);
	~Utilities(void);
};

