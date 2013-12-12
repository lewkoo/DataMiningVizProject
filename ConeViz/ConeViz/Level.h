#pragma once

#include "Itemset.h"
#include "Cluster.h"
#include <limits.h>
using namespace std;

#define DEFAULT_CIRCLE_LOCATION_X 0;
#define DEFAULT_CIRCLE_LOCATION_Y 0;
#define DEFAULT_CIRCLE_LOCATION_Z 0;

#define Y_RASING_FACTOR 10;
#define RADIUS_EXPANSION_FACTOR 10;

#define SELECTED_SPHERE_RADIUS_EXPANSION_FACTOR 4

class Level
{

private:

	int levelId;
	int minFrequency;
	int maxFrequency;

	bool isClustered;
	
	int circle_radius;
	int circle_X;
	int circle_Y;
	int circle_Z;
	
	std::vector<Cluster*> clusters;
	std::vector<Itemset*> itemsets;

public:
	Level(void);
	~Level(void);
	
	Level(int levelId);
	Level(std::vector<Itemset*> itemsets);

	void addItemset(Itemset* itemset);
	//bool removeItemset(Itemset itemset); //success:failure

	void calculateItemsetLocations();
	void drawItemsets();

	void setYCoordinate(int newY);

	int getYCoordinate();
	int getLevelId();

	std::vector<Itemset*> getItemsets();

};

