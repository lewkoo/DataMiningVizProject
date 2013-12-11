#pragma once

#include "Level.h"
#include "Itemset.h"

#include <iostream>
#include <sstream>
#include <direct.h>

#include <string>
#include <algorithm>
#include <iterator>

using namespace std;



class Utilities
{
private:
	static void parseLine(std::string lineToParse, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels);

public:

	static enum SHAPE_TYPES {FLAT_CONE, NORMAL_CONE, INVERTED_CONE};

	static void generateRandomItemsets(std::vector<Itemset>* itemsets); //TODO: add number of elements
	static void loadItemsets(ofFile fileToOpen, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels);
	static void setYCoordinates(std::vector<Level*>* levels, SHAPE_TYPES newShape);
	static void drawConnections(Level top, Level bottom);

	Utilities(void);
	~Utilities(void);
};

