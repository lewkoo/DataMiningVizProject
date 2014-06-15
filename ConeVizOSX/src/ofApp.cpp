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
            
        case 'F':
        case 'f':
            ofToggleFullscreen();
            break;
        case 'H':
        case 'h':
            if(helpLabel->isVisible()){
                helpLabel->setVisible(false);
                filesDropDown->setVisible(true);
            }
            else{
                helpLabel->setVisible(true);
                filesDropDown->setVisible(false);
            }
            break;
        case 'C':
        case 'c':
            if(fileControlls->isVisible())
            {
                fileControlls->setVisible(false);
                strategyControlls->setVisible(false);
                
            }else
            {
                fileControlls->setVisible(true);
                strategyControlls->setVisible(true);
            }
            
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
void ofApp::setUpParser() // file index in the drop-down menu
{
    //1.0 - Grab the singleton
    dataSource = DataParser::getInstance();

    //1.2 - Build & inicialize the file store - redundant on further loads, but isn't costly
    dataSource->buildFileStore();
    //1.3 - Set the current file
    dataSource->setCurrentFile(dataSource->getDataFiles()[0]);
    //1.4 - Load the file
    dataSource->analizeFile();
    
}

//--------------------------------------------------------------
void ofApp::changeFileSource(int indexOfFileToLoad)
{
    //1.0 - Unload the file, even if initial load - doesn't matter
    dataSource->unloadFile();
    
    //1.1 - Set the current file
    dataSource->setCurrentFile(dataSource->getDataFiles()[indexOfFileToLoad]);
    
    //1.2 - Load the file
    dataSource->analizeFile();
}

//--------------------------------------------------------------
void ofApp::setUpGUI()
{
    //1.0 - Set up the File controlls panells
    
    //1.1 - Inicialize the pannel
    fileControlls = new ofxUICanvas( 10,10, GUI_WIDTH, GUI_HEIGHT);
    
    //1.2 - Add a label
	fileControlls->addWidgetDown(new ofxUILabel("ConeViz Visualization Builder Tool", OFX_UI_FONT_LARGE));
    
    //1.3 - Add another label
    fileControlls->addWidgetDown(new ofxUILabel("\n* press 'h' for help & controls", OFX_UI_FONT_MEDIUM));
    
    //1.4 - Add a helper label, make invisible
    helpLabel = fileControlls->addWidgetDown(new ofxUILabel("\n\nPress \"F\" for full screen/window mode \n\nPress \"C\" to hide controls", OFX_UI_FONT_MEDIUM));
	helpLabel->setVisible(false);
    
    //1.5 - Add a drop down for file source select
    filesDropDown = fileControlls->addDropDownList("DATASETS", dataSource->getDataFiles(), 300);
    
	//hook up the listener
	ofAddListener(fileControlls->newGUIEvent, this, &ofApp::fileControllsGuiEvent);

    

}

//--------------------------------------------------------------
void ofApp::fileControllsGuiEvent(ofxUIEventArgs &e)
{
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
	ofLog() << "got event from: " << name << endl;

    if(name == "DATASETS") //catch an event from the drop down
	{
		ofxUIDropDownList *dropdown = (ofxUIDropDownList *) e.widget;
        
		vector<ofxUIWidget *> &selected = dropdown->getSelected();
        int availiable_files_count = dataSource->getDataFiles().size();
        
        if (selected.size() > 0) //check if anything is selected
        {
			std::string selected_name = selected[0]->getName();
            
			for(int i = 0; i < availiable_files_count; i++)
			{
				if(selected_name.compare( dataSource->getDataFiles()[i] ) == 0)
				{
					changeFileSource(i); //load the newly selected file
				}
			}
            
		}
        
	}
    
    
    
}

//--------------------------------------------------------------
void ofApp::shapeStrategyGuiEvent(ofxUIEventArgs &e)
{
    
}
