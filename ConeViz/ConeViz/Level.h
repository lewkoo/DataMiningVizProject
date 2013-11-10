#pragma once

#include "Itemset.h"
using namespace std;

#define DEFAULT_CIRCLE_LOCATION_X 0;
#define DEFAULT_CIRCLE_LOCATION_Y 0;
#define DEFAULT_CIRCLE_LOCATION_Z 0;


class Level
{

private:

	static int levelNextId;
	int getNextId() { return ++levelNextId; }

	int levelId;
	
	int circle_radius;
	int circle_X;
	int circle_Y;
	int circle_Z;
	std::vector<Itemset> itemsets;

public:
	Level(void);
	~Level(void);

	Level(std::vector<Itemset> itemsets);

	void addItemset(Itemset itemset);
	bool removeItemset(Itemset itemset); //success:failure

	void calculateItemsetLocations();
	void drawItemsets();

	void setYCoordinate();

	int getYCoordinate();

};

