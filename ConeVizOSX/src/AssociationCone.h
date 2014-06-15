//
//  AssociationCone.h
//  ConeVizOSX
//
//  Created by Levko Ivanchuk on 2014-06-15.
//
//

#ifndef __ConeVizOSX__AssociationCone__
#define __ConeVizOSX__AssociationCone__

#include <iostream>
#include "Strategy.h"

class AssociationCone : public Strategy {
    
    
public:
    void initializeStrategy();
    ofxUICanvas* drawGui(ofxUICanvas* panel);
    

};

#endif /* defined(__ConeVizOSX__AssociationCone__) */
