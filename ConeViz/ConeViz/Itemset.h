#pragma once

#include <iostream>
#include "ofMain.h"

using namespace std;

#define DEFAULT_SPHERE_RADIUS 2

class Itemset
{



private:
	
	//ID generator
	static int sNextId;
	int getNextId() { return ++sNextId; }

	
	int itemsetId; //Id of the current itemset
	//int level; //this value is derived from singletons
	int radius; //represents the radius of the sphere

	vector< string > singletons; //Itemset singletons (is also unique)
	int frequency; //Itemset frequency
	ofPoint location; //location in the visualization
	ofColor color; //color

	
	
public:
	Itemset(void);
	~Itemset(void);

	static bool sortByFrequency(Itemset* lhs, Itemset* rhs);
	
	void setLocation(ofPoint newLocation);
	void setColor(ofColor newColor);
	void setFrequency(int newFrequency);

	bool isCurrentlySelected;

	int getLevel();
	int getFrequency();
	string getName();
	ofPoint getLocation();
	ofColor getColor();
	int getRadius();

	void addSingletonToItemset(string singletonName);




};

