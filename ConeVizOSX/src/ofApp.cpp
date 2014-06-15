#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    setUpParser();
    setUpGUI();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key) {
        case 'C':
        case 'c':
            //if(cam.getMouseInputEnabled()) cam.disableMouseInput();
            //else cam.enableMouseInput();
            break;
            
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            if(helpLabel->isVisible()){
                helpLabel->setVisible(false);
                filesDropDown->setVisible(true);
                //shapeHeightSlider->setVisible(true);
                //clusteringBoundarySlider->setVisible(true);
                //frequencyLineThreshold->setVisible(true);
                //lineCalculation->setVisible(true);
            }
            else{
                helpLabel->setVisible(true);
                filesDropDown->setVisible(false);
                //shapeHeightSlider->setVisible(false);
                //clusteringBoundarySlider->setVisible(false);
                //frequencyLineThreshold->setVisible(false);
                //lineCalculation->setVisible(false);
            }
            
            break;
        case 'A':
        case 'a':
            //renderAxis = !renderAxis;
            break;
    }
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
void ofApp::setUpParser()
{
    dataSource = DataParser::getInstance();
    dataSource->buildFileStore();
    dataSource->setCurrentFile(dataSource->getDataFiles()[0]);
    dataSource->analizeFile();
    
    
    
}

//--------------------------------------------------------------
void ofApp::setUpGUI()
{
    fileControlls = new ofxUICanvas( 10,10, GUI_WIDTH, GUI_HEIGHT);
	fileControlls->addWidgetDown(new ofxUILabel("ConeViz Visualization Builder Tool", OFX_UI_FONT_LARGE));
    
    fileControlls->addWidgetDown(new ofxUILabel("\n* press 'h' for help & controls", OFX_UI_FONT_MEDIUM));
    
    //\n\n\nPress \"F\" for full screen/window mode \n\nPress \"C\" to hide controls and see only the preview of the shape
    
    helpLabel = fileControlls->addWidgetDown(new ofxUILabel("\n\nPress \"F\" for full screen/window mode \n\nPress \"C\" to hide controls", OFX_UI_FONT_MEDIUM));
	helpLabel->setVisible(false);
    
    filesDropDown = fileControlls->addDropDownList("DATASETS", dataSource->getDataFiles(), 200);
    
	//hook up the listener
	ofAddListener(fileControlls->newGUIEvent, this, &ofApp::fileControllsGuiEvent);


    
    
}

//--------------------------------------------------------------
void ofApp::fileControllsGuiEvent(ofxUIEventArgs &e)
{

}

//--------------------------------------------------------------
void ofApp::shapeStrategyGuiEvent(ofxUIEventArgs &e)
{

}
