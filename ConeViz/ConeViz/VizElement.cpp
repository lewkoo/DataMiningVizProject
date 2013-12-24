#include "VizElement.h"


VizElement::VizElement(void)
{
	isCurrentlySelected = false;
}


VizElement::~VizElement(void)
{
}

ofPoint VizElement::getLocation()
{
	return location;
}

ofColor VizElement::getColor()
{
	return color;
}

int VizElement::getRadius()
{
	return radius;
}

int VizElement::getMeshID()
{
	return meshId;
}

bool VizElement::getIsCurrentlySelected()
{
	return isCurrentlySelected;
}

void VizElement::setLocation(ofPoint newPoint)
{
	this->location = newPoint;
}

void VizElement::setColor(ofColor newColor)
{
	this->color=newColor;
}

void VizElement::setRadius(int newRadius)
{
	this->radius = newRadius;
}

void VizElement::setSelected(bool newValue)
{
	this->isCurrentlySelected = newValue;
}

void VizElement::setMeshID(int newId)
{
	this->meshId = newId;
}