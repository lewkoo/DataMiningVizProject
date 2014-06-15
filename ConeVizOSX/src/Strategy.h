//
//  Strategy.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-14.
//
//

#ifndef ConeVizOSX_Strategy_h
#define ConeVizOSX_Strategy_h

#include "ofMain.h"
#include "ofxUI.h"

#define STRATEGY_GUI_X 420
#define STRATEGY_GUI_Y 100

#define STRATEGY_GUI_HEIGHT 500
#define STRATEGY_GUI_WIDTH 400

class Strategy {

    
public:
    virtual void initializeStrategy() = 0;
    virtual ofxUICanvas* drawGui(ofxUICanvas* panel) = 0;

};

#endif
