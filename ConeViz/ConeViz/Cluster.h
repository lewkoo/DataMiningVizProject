#pragma once

#include <limits.h>
#include "Itemset.h"
#include "VizElement.h"
using namespace std;

class Cluster : public VizElement
{
private:

	//Boundaries of a cluster
	int minFrequency;
	int maxFrequency;

	std::vector<Itemset*> itemsets;

public:
	Cluster(void);
	~Cluster(void);

	Cluster(int minFrequency, int maxFrequency);
	
	//getters
	int getMinFrequency();
	int getMaxFrequency();
	string getName();
	int getFrequency();

	//setters
	void setMinFrequency(int newFrequency);
	void setMaxFrequency(int newFrequency);

	void addItemset(Itemset* newItemset);

};

