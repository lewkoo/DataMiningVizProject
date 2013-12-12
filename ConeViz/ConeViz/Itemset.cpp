#include "Itemset.h"

int Itemset::sNextId = 0;


Itemset::Itemset(void)
{
	this->itemsetId = getNextId();
	this->isCurrentlySelected = false;
	this->radius = DEFAULT_SPHERE_RADIUS;
}


Itemset::~Itemset(void)
{
}

void Itemset::setLocation(ofPoint newPoint)
{
	this->location = newPoint;
}

void Itemset::setColor(ofColor newColor)
{
	this->color=newColor;
}

void Itemset::setFrequency(int newFrequency)
{
	this->frequency = newFrequency;
}

void Itemset::addSingletonToItemset(string singletonName)
{
	singletons.push_back(singletonName);
}

string Itemset::getName()
{
	string toReturn = "";

	for(int i = 0; i < singletons.size(); i++)
	{
		toReturn.append(singletons[i]);
		toReturn.append(" ");
	}

	return toReturn;
}

int Itemset::getRadius()
{
	return radius;
}

int Itemset::getLevel()
{
	//returns the number of singletons in the itemset
	return singletons.size();
}

int Itemset::getFrequency()
{
	return frequency;
}

ofPoint Itemset::getLocation()
{
	return location;
}

ofColor Itemset::getColor()
{
	return color;
}

