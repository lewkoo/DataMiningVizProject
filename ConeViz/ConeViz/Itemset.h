#pragma once

#include <iostream>
#include "ofMain.h"

using namespace std;

class Itemset
{

private:
	
	//ID generator
	static int sNextId;
	int getNextId() { return ++sNextId; }

	
	int itemsetId; //Id of the current itemset
	int level; //represents the level of the itemset (singleton, 2itemset, 3itemset, etc)

	string name; //Itemset name (is also unique)
	ofPoint location; //location in the visualization
	ofColor color; //color
	
public:
	Itemset(void);
	Itemset(string name, ofPoint location = ofPoint(0,0,0), ofColor color = ofColor(0,0,0));
	~Itemset(void);

	void setLevel(int newLevel);
	void setLocation(ofPoint newLocation);
	void setColor(ofColor newColor);

	int getLevel();
	ofPoint getLocation();
	ofColor getColor();


};

