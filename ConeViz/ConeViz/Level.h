#pragma once

#include "Itemset.h"
using namespace std;

class Level
{

private:

	static int levelNextId;
	int getNextId() { return ++levelNextId; }

	int levelId;
	int y_coordinate;
	std::vector<Itemset> itemsets;

public:
	Level(void);
	~Level(void);

	Level(std::vector<Itemset> itemsets);

	//void addItemset(Itemset itemset);
	//bool removeItemset(Itemset itemset); //success:failure

	//void calculateItemsetLocations();
	//void drawItemsets();

	//void setYCoordinate();

	//int getYCoordinate();

};

