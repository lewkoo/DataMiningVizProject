#include "Cluster.h"


Cluster::Cluster(void)
{
	minFrequency = INT_MAX;
	maxFrequency = INT_MIN;

}


Cluster::~Cluster(void)
{
}

Cluster::Cluster(int minFrequency, int maxFrequency)
{
	this->minFrequency = minFrequency;
	this->maxFrequency = maxFrequency;
}

int Cluster::getMinFrequency()
{
	return this->minFrequency;
}

int Cluster::getMaxFrequency()
{
	return this->maxFrequency;
}

string Cluster::getName()
{
	string toReturn = "";

	for(int j = 0; j < itemsets.size(); j++)
	{
		toReturn.append(itemsets[j]->getName());
		toReturn.append(" ");
	}

	return toReturn;
}


void Cluster::setMinFrequency(int newFrequency)
{
	this->minFrequency = newFrequency;
}

void Cluster::setMaxFrequency(int newFrequency)
{
	this->maxFrequency = newFrequency;
}

void Cluster::addItemset(Itemset* itemset)
{
	if(itemset->getFrequency() > maxFrequency)
		maxFrequency = itemset->getFrequency();

	if(itemset->getFrequency() < minFrequency)
		minFrequency = itemset->getFrequency();

	itemsets.push_back(itemset);
}