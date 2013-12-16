#pragma once

#include <iostream>
#include "ofMain.h"
#include "VizElement.h"

using namespace std;

#define DEFAULT_SPHERE_RADIUS 2

class Itemset : public VizElement
{



private:
	
	//ID generator
	static int sNextId;
	int getNextId() { return ++sNextId; }

	int itemsetId; //Id of the current itemset
	vector< string > singletons; //Itemset singletons (is also unique)
	int frequency; //Itemset frequency

public:
	Itemset(void);
	~Itemset(void);

	static bool sortByFrequency(Itemset* lhs, Itemset* rhs);
	

	void setFrequency(int newFrequency);

	int getLevel();
	int getFrequency();
	string getName();


	void addSingletonToItemset(string singletonName);




};

