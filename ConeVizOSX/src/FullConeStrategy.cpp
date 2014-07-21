//
//  FullConeStrategy.cpp
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-15.
//
//

#include "FullConeStrategy.h"

void FullConeStrategy::initializeStrategy(DataParser *dataSource)
{
    visualizationMesh = ofMesh();
    currDataSource = dataSource;
}

void FullConeStrategy::draw()
{
 
    
    Itemset* currentItemset = currDataSource->getNextItemset();
    
    while(currentItemset != NULL)
    {
        ofLog() << currentItemset->getName() << " " << currentItemset->getFrequency();
    
        currentItemset = currDataSource->getNextItemset();
        
    }
    

    
}

ofxUICanvas* FullConeStrategy::drawGui(ofxUICanvas* panel)
{
    
    panel = new ofxUICanvas( STRATEGY_GUI_X, STRATEGY_GUI_Y, STRATEGY_GUI_WIDTH, STRATEGY_GUI_HEIGHT);
    
    
    
    return panel;
    
}