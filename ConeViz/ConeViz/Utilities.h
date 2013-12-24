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
	static int Y_RASING_FACTOR;

public:

	

	static enum SHAPE_TYPES {FLAT_CONE, NORMAL_CONE, INVERTED_CONE};
	static void loadItemsets(ofFile fileToOpen, std::vector<Itemset*>* itemsets, std::vector<Level*>* levels);
	static void setYCoordinates(std::vector<Level*>* levels, SHAPE_TYPES newShape);
	static void setConnections(Level top, Level bottom, ofMesh* mesh, int lineFrequencyThreshold);
	static int findMaxFreq(std::vector<Level*>* levels);

	static int getYRasingFactor();
	static void setYRasingFactor(int newY);

	Utilities(void);
	~Utilities(void);
};

