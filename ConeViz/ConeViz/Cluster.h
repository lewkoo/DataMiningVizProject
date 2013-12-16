#pragma once

#include "Itemset.h"
using namespace std;

class Cluster
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

	//setters
	void setMinFrequency(int newFrequency);
	void setMaxFrequency(int newFrequency);

	void addItemset(Itemset* newItemset);

};

