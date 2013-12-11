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

Itemset::Itemset(string name, ofPoint location, ofColor color)
{
	this->itemsetId = getNextId();

	//this->name = name;
	//this->level = this->name.length()-1;

	this->location = location;
	this->color = color;
	this->isCurrentlySelected = false;
	this->radius = DEFAULT_SPHERE_RADIUS;
}

void Itemset::setLocation(ofPoint newPoint)
{
	this->location = newPoint;
}

void Itemset::setLevel(int newLevel)
{
	this->level = newLevel;
}

void Itemset::setColor(ofColor newColor)
{
	this->color=newColor;
}

string Itemset::getName()
{
	return "|";
}

int Itemset::getRadius()
{
	return radius;
}

int Itemset::getLevel()
{
	return level;
}

ofPoint Itemset::getLocation()
{
	return location;
}

ofColor Itemset::getColor()
{
	return color;
}