//
//  FullConeStrategy.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-15.
//
//

#ifndef __ConeVizOSX__FullConeStrategy__
#define __ConeVizOSX__FullConeStrategy__

#include <iostream>
#include "Strategy.h"

class FullConeStrategy : public Strategy {
    
    
public:
    void initializeStrategy(DataParser *dataSource);
    ofxUICanvas* drawGui(ofxUICanvas* panel);
    
    void draw();
    
    

};


#endif /* defined(__ConeVizOSX__FullConeStrategy__) */
