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
	itemsets = std::vector<Itemset>();

	Utilities::loadItemsets("classDataset.txt", &itemsets);




}

//--------------------------------------------------------------
void coneVizApp::update(){
	
}

//--------------------------------------------------------------
void coneVizApp::draw(){
	
	cam.begin();		
	ofRotateX(ofRadToDeg(.5));
	ofRotateY(ofRadToDeg(-.5));
	
	ofBackground(0);
	
	ofSetColor(255,0,0);
	ofFill();
	ofBox(30);
	ofNoFill();
	ofSetColor(0);
	ofBox(30);
	
	ofPushMatrix();
	ofTranslate(0,0,20);
	ofSetColor(0,0,255);
	ofFill();
	ofBox(5);
	ofNoFill();
	ofSetColor(0);
	ofBox(5);
	ofPopMatrix();
	cam.end();
	drawInteractionArea();
	ofSetColor(255);

	//draw fps 
	string msg = "\n\nfps: " + ofToString(ofGetFrameRate(), 2);
	ofDrawBitmapStringHighlight(msg, 10, 20);
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
