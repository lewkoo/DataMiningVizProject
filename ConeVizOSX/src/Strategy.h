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

class Strategy {

    
public:
    virtual void initializeStrategy() = 0;
    virtual void drawGui(ofxUICanvas* panel) = 0;
};

#endif
