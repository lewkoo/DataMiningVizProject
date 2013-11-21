#include "coneVizApp.h"


//--------------------------------------------------------------
void coneVizApp::setup(){
        //GRAPHICS SET UP
        ofSetVerticalSync(true);
        
        // this uses depth information for occlusion
        // rather than always drawing things on top of each other
        glEnable(GL_DEPTH_TEST);
        
        // this sets the camera's distance from the object
        cam.setDistance(100);
        
        ofSetCircleResolution(64);
        bShowHelp = true;
        //END OF GRAPHICS SET UP

        //LOAD THE DATASET
        itemsets = std::vector<Itemset*>();
		levels = std::vector<Level*>();

        Utilities::loadItemsets("classDataset.txt", &itemsets, &levels);

		Utilities::setYCoordinates(&levels, Utilities::SHAPE_TYPES::NORMAL_CONE); // goes over all the levels and sets the Y coordinates

}

//--------------------------------------------------------------
void coneVizApp::update(){
        
}

//--------------------------------------------------------------
void coneVizApp::draw(){
        
    cam.begin();                
    ofRotateX(ofRadToDeg(.5));
    ofRotateY(ofRadToDeg(-.5));

	ofBackground(255);

    drawAxis();
        
    for(int i = 0; i < levels.size(); i++)
    {
		levels[i]->calculateItemsetLocations();
		levels[i]->drawItemsets();
    }

	for(int i = 0; i < levels.size()-1; i++)
	{
		Utilities::drawConnections(*levels[i], *levels[i+1]);
	}



    cam.end();
    drawInteractionArea();
    ofSetColor(255);

    //draw fps 
    string msg = "\n\nfps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapStringHighlight(msg, 10, 20);

	msg = "\nMouse location : ";

	ostringstream convert;

	convert << mouseX;
	convert << " ";
	convert << mouseY;

	msg = msg + (convert.str());
    ofDrawBitmapStringHighlight(msg, 10, 80);

	msg = "\nWorld locaiton: ";

	ofVec3f worldCoordinates = cam.screenToWorld(ofVec3f((float)mouseX, (float)mouseY));

	ostringstream convert2;

	convert2 << worldCoordinates.x;
	convert2 << " ";
	convert2 << worldCoordinates.y;
	convert2 << " ";
	convert2 << worldCoordinates.z;

	ofDrawBitmapStringHighlight(convert2.str(), 10, 120);

}
//--------------------------------------------------------------
void coneVizApp::drawInteractionArea(){
        ofRectangle vp = ofGetCurrentViewport();
        float r = MIN(vp.width, vp.height) * 0.5f;
        float x = vp.width * 0.5f;
        float y = vp.height * 0.5f;
        
        ofPushStyle();
        ofSetLineWidth(3);
        ofSetColor(255, 255, 0);
        ofNoFill();
        glDepthMask(false);
        ofCircle(x, y, r);
        glDepthMask(true);
        ofPopStyle();
}

//--------------------------------------------------------------
void coneVizApp::drawAxis()
{
    ofPoint origin = ofPoint(0,0,0);
    ofFill();

	ofSetLineWidth(2);

    ofSetColor(255,0,0);
    ofLine(origin, ofPoint(100,0,0));
    ofLine(ofPoint(-100,0,0), origin);

    ofSetColor(0,255,0);
    ofLine(origin, ofPoint(0,100,0));
    //ofLine(ofPoint(0,-100,0), origin);

    ofSetColor(0,0,255);
    ofLine(origin, ofPoint(0,0,100));
    ofLine(ofPoint(0,0,-100), origin);

	ofNoFill();
}
//--------------------------------------------------------------
void coneVizApp::keyPressed(int key){
        switch(key) {
                case 'C':
                case 'c':
                        if(cam.getMouseInputEnabled()) cam.disableMouseInput();
                        else cam.enableMouseInput();
                        break;
                        
                case 'F':
                case 'f':
                        ofToggleFullscreen();
                        break;
                case 'H':
                case 'h':
                        bShowHelp ^=true;
                        break;
        }
}

//--------------------------------------------------------------
void coneVizApp::keyReleased(int key){
        
}

//--------------------------------------------------------------
void coneVizApp::mouseMoved(int x, int y ){
 
	mouseX = x;
	mouseY = y;

}

//--------------------------------------------------------------
void coneVizApp::mouseDragged(int x, int y, int button){
        
}

//--------------------------------------------------------------
void coneVizApp::mousePressed(int x, int y, int button){
        
}

//--------------------------------------------------------------
void coneVizApp::mouseReleased(int x, int y, int button){
        
}

//--------------------------------------------------------------
void coneVizApp::windowResized(int w, int h){
        
}

//--------------------------------------------------------------
void coneVizApp::gotMessage(ofMessage msg){
        
}

//--------------------------------------------------------------
void coneVizApp::dragEvent(ofDragInfo dragInfo){ 
        
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               