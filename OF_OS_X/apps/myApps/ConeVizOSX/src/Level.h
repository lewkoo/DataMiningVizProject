//
//  Level.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-05-22.
//
//

#ifndef __ConeVizOSX__Level__
#define __ConeVizOSX__Level__


#pragma once

#include "VizElement.h"
#include "Itemset.h"
#include "Cluster.h"
#include <limits.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define DEFAULT_CIRCLE_LOCATION_X 0;
#define DEFAULT_CIRCLE_LOCATION_Y 0;
#define DEFAULT_CIRCLE_LOCATION_Z 0;

#define RADIUS_EXPANSION_FACTOR 10;

#define SELECTED_SPHERE_RADIUS_EXPANSION_FACTOR 4

class Level
{
    
private:
    
	static int clusteringFactor; //cluster by frequency
	static int clusteringBoundary; // clusters if the number of itemsets reaches over this number
    
	int levelId;
	int minFrequency;
	int maxFrequency;
    
	bool isClustered;
	
	int circle_radius;
	int circle_X;
	int circle_Y;
	int circle_Z;
	
	std::vector<VizElement*> elements;
    
	std::vector<Itemset*> itemsets;
    
public:
	Level(void);
	~Level(void);
	
	Level(int levelId);
	Level(std::vector<VizElement*> itemsets);
    
	void addItemset(Itemset* itemset);
    
	void calculateItemsetLocations();
	void drawItemsets();
    
	static void setClusteringFactor(int newClusteringFactor);
	static void setClusteringBoundary(int newBoundary);
    
	void setYCoordinate(int newY);
    
	int getYCoordinate();
	int getMaxFrequency();
	int getLevelId();
	bool getIsClustered();
    
	std::vector<VizElement*> getVizElements();
	std::vector<Itemset*> getItemsets();
    
	
};



#endif /* defined(__ConeVizOSX__Level__) */
