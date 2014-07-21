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
 
    string currentLine = currDataSource->getNextLine();
    
    while ( !currentLine.empty()) {
        ofLog() << currentLine << endl;
        currentLine = currDataSource->getNextLine();
    }
    
}

ofxUICanvas* FullConeStrategy::drawGui(ofxUICanvas* panel)
{
    
    panel = new ofxUICanvas( STRATEGY_GUI_X, STRATEGY_GUI_Y, STRATEGY_GUI_WIDTH, STRATEGY_GUI_HEIGHT);
    
    
    
    return panel;
    
}