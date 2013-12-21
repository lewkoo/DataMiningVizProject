#pragma once

#include "ofMain.h"

class VizElement
{

protected:
	
	int radius; //represents the radius of the sphere
	ofPoint location; //location in the visualization
	ofColor color; //color
	bool isCurrentlySelected;

public:
	VizElement(void);
	~VizElement(void);

	ofPoint getLocation();
	ofColor getColor();
	int getRadius();
	bool getIsCurrentlySelected();

	virtual string getName() = 0;
	virtual int getFrequency() = 0;

	void setLocation(ofPoint newLocation);
	void setColor(ofColor newColor);
	void setRadius(int newRadius);
	void setSelected(bool newValue);
};

