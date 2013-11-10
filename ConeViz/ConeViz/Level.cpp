#include "Level.h"

int Level::levelNextId = 0;


Level::Level(void)
{
	this->levelId = getNextId();
}


Level::~Level(void)
{
}

Level::Level(std::vector<Itemset> itemsets)
{

	this->itemsets = itemsets;
}

//void Level::addItemset()
//{
//
//}
