//
//  Itemset.cpp
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-05-22.
//
//

#include "Itemset.h"

int Itemset::sNextId = 0;

bool Itemset::sortByFrequency(Itemset* lhs, Itemset* rhs) { return lhs->getFrequency() < rhs->getFrequency(); }

Itemset::Itemset(void)
{
	this->itemsetId = getNextId();
	this->isCurrentlySelected = false;
	this->radius = DEFAULT_SPHERE_RADIUS;
}

Itemset::~Itemset(void)
{
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

string Itemset::getType()
{
	return "Itemset";
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


