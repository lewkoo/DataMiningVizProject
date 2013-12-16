#include "VizElement.h"


VizElement::VizElement(void)
{
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
