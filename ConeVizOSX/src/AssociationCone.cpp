//
//  AssociationCone.cpp
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-15.
//
//

#include "AssociationCone.h"

void AssociationCone::initializeStrategy(DataParser *dataSource)
{
    
}

void AssociationCone::draw()
{

}

ofxUICanvas* AssociationCone::drawGui(ofxUICanvas* panel)
{
    
    panel = new ofxUICanvas( STRATEGY_GUI_X, STRATEGY_GUI_Y, STRATEGY_GUI_WIDTH, STRATEGY_GUI_HEIGHT-200);
 
    return panel;
}

