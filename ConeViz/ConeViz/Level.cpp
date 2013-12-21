#include "Level.h"

int Level::clusteringFactor = 10;
int Level::clusteringBoundary = 200;

Level::Level(void)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;

	minFrequency = INT_MAX;
	maxFrequency = INT_MIN;

}


Level::~Level(void)
{
}

Level::Level(std::vector<VizElement*> itemsets)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;
	this->elements = itemsets;

	minFrequency = INT_MAX;
	maxFrequency = INT_MIN;

}

Level::Level(int levelId)
{
	circle_X = DEFAULT_CIRCLE_LOCATION_X;
	circle_Y = DEFAULT_CIRCLE_LOCATION_Y;
	circle_Z = DEFAULT_CIRCLE_LOCATION_Z;

	minFrequency = INT_MAX;
	maxFrequency = INT_MIN;


	this->levelId = levelId;
	this->circle_radius = levelId * RADIUS_EXPANSION_FACTOR;
	this->elements = std::vector<VizElement*>();
	this->itemsets = std::vector<Itemset*>();
}

void Level::addItemset(Itemset* itemset)
{
	if(itemset->getFrequency() > maxFrequency)
		maxFrequency = itemset->getFrequency();

	if(itemset->getFrequency() < minFrequency)
		minFrequency = itemset->getFrequency();

	itemsets.push_back(itemset);
}

void Level::calculateItemsetLocations()
{
	//Determine if clustering should be used
	if(itemsets.size() >= clusteringBoundary){
		isClustered = true;

		//Generate the clusters
		int numOfClusters = (int) ceil( (double) itemsets.size()/clusteringFactor);

		for(int i = 0; i < numOfClusters; i++)
		{
			elements.push_back(new Cluster());
		}
		//Sort the itemsets by frequency
		sort(itemsets.begin(), itemsets.end(), Itemset::sortByFrequency);
		//Push the itemsets to a cluster

		int currentClusterIndex = 0;
		int currentItemsetIndex = 0;

		for(int i = 0; i < itemsets.size(); i++)
		{
			if(currentItemsetIndex == clusteringFactor)
			{
				currentClusterIndex++;
				currentItemsetIndex = 0;
			}

			Cluster* currentCluster = dynamic_cast<Cluster*>(elements[currentClusterIndex]);
			currentItemsetIndex++;

			currentCluster->addItemset(itemsets[i]);
		}

	}//end if

	else
	{
		isClustered = false;

		for(int i = 0; i < itemsets.size(); i++)
		{
			elements.push_back(itemsets[i]);
		}

	}

	this->circle_radius = elements.size() * RADIUS_EXPANSION_FACTOR;

	for(int i = 0; i < elements.size(); i++)
	{

		float x = circle_X + circle_radius * cos(2 * PI * (i+1) / (elements.size()+1));                
		float z = circle_Z + circle_radius * sin(2 * PI * (i+1) / (elements.size()+1));

		elements[i]->setLocation(ofPoint(x,circle_Y,z));
		elements[i]->setColor(ofColor(150,150,150));
		elements[i]->setRadius(15);
	}
	

}

void Level::drawItemsets()
{
	//draw the circle of the level
	ofPushStyle();
	ofPushMatrix();
	ofRotateX(-90);
	ofSetColor(0,0,100);
	ofSetLineWidth(2);
	ofCircle(0,0,circle_Y, circle_radius);
	ofPopMatrix();
	ofPopStyle();


	for(int i = 0; i < elements.size(); i++)
	{
		VizElement* currentItemset = elements[i];
		ofPushStyle();
		ofPushMatrix();

		if(currentItemset->getIsCurrentlySelected() == true)
		{
			ofSetLineWidth(0.1);
			//ofTranslate(currentItemset->getLocation());
			ofSetColor(ofColor(0,139,238));
			ofSphere(currentItemset->getLocation(),currentItemset->getRadius()+SELECTED_SPHERE_RADIUS_EXPANSION_FACTOR);

		}else
		{
			ofFill();
			//ofTranslate(currentItemset->getLocation());
			ofSetColor(currentItemset->getColor());
			ofSphere(currentItemset->getLocation(), currentItemset->getRadius());
			ofNoFill();
		}

		ofPopMatrix();
		ofPopStyle();
	}

	

    
}

//GETTER
int Level::getLevelId()
{
	return this->levelId;
}

int Level::getMaxFrequency()
{
	return this->maxFrequency;
}

bool Level::getIsClustered()
{
	return isClustered;
}

std::vector<VizElement*> Level::getVizElements()
{
	return this->elements;
}

std::vector<Itemset*> Level::getItemsets()
{
	return this->itemsets;
}


//SETTER
void Level::setYCoordinate(int newY)
{
	this->circle_Y = newY;
}

void Level::setClusteringFactor(int newClusteringFactor)
{
	Level::clusteringFactor = newClusteringFactor;
}