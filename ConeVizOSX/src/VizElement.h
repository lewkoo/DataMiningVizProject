//
//  VizElement.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-24.
//
//

#ifndef __ConeVizOSX__VizElement__
#define __ConeVizOSX__VizElement__

#include <iostream>
#include "ofMain.h"

class VizElement
{
    
protected:
	
	int meshId; //represents the vertex id in the mesh
	int radius; //represents the radius of the sphere
	ofPoint location; //location in the visualization
	ofColor color; //color
	bool isCurrentlySelected;
    
public:
	VizElement(void);
	~VizElement(void);
    
	int getMeshID();
	ofPoint getLocation();
	ofColor getColor();
	int getRadius();
	bool getIsCurrentlySelected();
    
	virtual string getName() = 0;
	virtual string getType() = 0;
	virtual int getFrequency() = 0;
    
	void setLocation(ofPoint newLocation);
	void setColor(ofColor newColor);
	void setRadius(int newRadius);
	void setSelected(bool newValue);
	void setMeshID(int newID);
};


#endif /* defined(__ConeVizOSX__VizElement__) */
