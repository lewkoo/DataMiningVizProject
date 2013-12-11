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
	int level; //represents the level of the itemset (singleton, 2itemset, 3itemset, etc)
	int radius; //represents the radius of the sphere

	vector< string > name; //Itemset name (is also unique)
	int frequency; //Itemset frequency
	ofPoint location; //location in the visualization
	ofColor color; //color

	
	
public:
	Itemset(void);
	Itemset(string name, ofPoint location = ofPoint(0,0,0), ofColor color = ofColor(0,0,0));
	~Itemset(void);

	void setLevel(int newLevel);
	void setLocation(ofPoint newLocation);
	void setColor(ofColor newColor);

	bool isCurrentlySelected;

	int getLevel();
	string getName();
	ofPoint getLocation();
	ofColor getColor();
	int getRadius();


};

