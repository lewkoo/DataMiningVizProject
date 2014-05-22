#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //GRAPHICS SET UP
    ofSetVerticalSync(true);
    
    // this uses depth information for occlusion
    // rather than always drawing things on top of each other
    glEnable(GL_DEPTH_TEST);
    // this sets the camera's distance from the object
    cam.setAutoDistance(true);
    cam.setFarClip((float)60000.0);
    
    ofSetCircleResolution(64);
    bShowHelp = true;
    //END OF GRAPHICS SET UP
    
    //Set up the GUI
    setUpGUI();
    
    renderAxis = false;
    calculateLines = true;
    
    //PROCESS THE DATASETS
    scanForFiles(); // populate the combo box with data file names
    
    itemsets = std::vector<Itemset*>();
    levels = std::vector<Level*>();
    lineFrequencyThreshold = 1;
    Utilities::setYRasingFactor(DEFAULT_SHAPE_HEIGHT);
    
    //prepare the shape
    refreshViz();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
