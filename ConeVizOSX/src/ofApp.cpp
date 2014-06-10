#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    dataSource = DataParser::getInstance();
    dataSource->buildFileStore();
    
    dataSource->setCurrentFile("Results_10_10k5L.txt");
    
    dataSource->analizeFile();
    
    dataSource->unloadFile();
    
    setUpGUI();
    
    filesDropDown = mainGUI->addDropDownList("DATASETS", dataSource->getDataFiles(), 200);
    
    
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

//--------------------------------------------------------------
void ofApp::setUpGUI()
{
    mainGUI = new ofxUICanvas( 10,10, GUI_WIDTH, GUI_HEIGHT);
	mainGUI->addWidgetDown(new ofxUILabel("ConeViz Visualization Tool", OFX_UI_FONT_LARGE));
	mainGUI->addWidgetEastOf(new ofxUILabel("     * press 'h' for help & controls", OFX_UI_FONT_MEDIUM), "ConeViz Visualization Tool", false);
    
	helpLabel = mainGUI->addLabel("Help & Controls", "\n\n\nPress \"F\" for full screen/window mode \n\nPress \"M\" and drag the mouse to shift the centre of the shape \n\nPress \"C\" to turn off the camera interactions \n\nPress \"A\" to turn axis rendering on/off");
	helpLabel->setVisible(false);
    
    
	//hook up the listener
	ofAddListener(mainGUI->newGUIEvent, this, &ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::guiEvent(ofxUIEventArgs &e)
{

}
