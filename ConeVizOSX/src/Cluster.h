//
//  Cluster.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-05-22.
//
//

#ifndef __ConeVizOSX__Cluster__
#define __ConeVizOSX__Cluster__

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
	string getType();
	int getFrequency();
    
	//setters
	void setMinFrequency(int newFrequency);
	void setMaxFrequency(int newFrequency);
    
	void addItemset(Itemset* newItemset);
    
};



#endif /* defined(__ConeVizOSX__Cluster__) */
