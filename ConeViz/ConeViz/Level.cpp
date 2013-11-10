#include "Level.h"

int Level::levelNextId = 0;


Level::Level(void)
{
	this->levelId = getNextId();
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;
}


Level::~Level(void)
{
}

Level::Level(std::vector<Itemset> itemsets)
{
	Level();
	this->itemsets = itemsets;
}

void Level::addItemset(Itemset itemset)
{
	itemsets.push_back(itemset);
}

bool Level::removeItemset(Itemset itemset)
{
	//bad solution - iterate over the list, remove the item
	return true;
}

void Level::calculateItemsetLocations()
{
	int circleRadius = 2;
    int circleX = 0;
    int circleY = 0;

    for(int i = 0; i < itemsets.size(); i++)
    {

		double x = circle_X + circle_radius * cos(2 * PI * i / itemsets.size());                
		double z = circle_Z + circle_radius * sin(2 * PI * i / itemsets.size());

		itemsets[i].setLocation(ofPoint(x,circle_Y,z));
		itemsets[i].setColor(ofColor(30,30,30));

    }
}


