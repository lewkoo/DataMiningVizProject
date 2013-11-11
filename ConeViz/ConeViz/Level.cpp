#include "Level.h"

Level::Level(void)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;
}


Level::~Level(void)
{
}

Level::Level(std::vector<Itemset> itemsets)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;
	this->itemsets = itemsets;
}

Level::Level(int levelId)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;


	this->levelId = levelId;
	this->circle_radius = levelId * RADIUS_EXPANSION_FACTOR;
	this->itemsets = std::vector<Itemset>();
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

    for(int i = 0; i < itemsets.size(); i++)
    {

		double x = circle_X + circle_radius * cos(2 * PI * i / itemsets.size());                
		double z = circle_Z + circle_radius * sin(2 * PI * i / itemsets.size());

		itemsets[i].setLocation(ofPoint(x,circle_Y,z));
		itemsets[i].setColor(ofColor(150,150,150));

    }
}

void Level::drawItemsets()
{
	//draw the circle of the level
	ofPushMatrix();
	ofRotateX(-90);
	ofSetColor(0,0,100);
	ofCircle(0,0,circle_Y, circle_radius);
	ofPopMatrix();

    for(int i = 0; i < itemsets.size(); i++)
    {
            Itemset currentItemset = itemsets[i];
            ofPushMatrix();
			ofFill();
            ofTranslate(currentItemset.getLocation());
            ofSetColor(currentItemset.getColor());
            ofSphere(2);
			ofNoFill();
            ofPopMatrix();
    }
}


//GETTER
int Level::getLevelId()
{
	return this->levelId;
}

//SETTER
void Level::setYCoordinate(int newY)
{
	this->circle_Y = newY;
}