#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    setUpParser();
    setUpGUI();
    
    //set up the current strategy
    //default to Full cone strategy
    currentStrategy = new FullConeStrategy();
    currentStrategy->initializeStrategy(dataSource);
    currentStrategyControlls = currentStrategy->drawGui(currentStrategyControlls);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //draw the preview of the current visualization
    currentStrategy->draw();
    
    
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
    fileControlls = new ofxUICanvas( 10,10, FILE_CONTROL_WIDTH, FILE_CONTROL_HEIGHT);
    
    //1.2 - Add a label
	fileControlls->addWidgetDown(new ofxUILabel("ConeViz Visualization Builder Tool", OFX_UI_FONT_LARGE));
    
    //1.3 - Add another label
    fileControlls->addWidgetDown(new ofxUILabel("\n* press 'h' for help & controls", OFX_UI_FONT_MEDIUM));
    
    //1.4 - Add a helper label, make invisible
    helpLabel = fileControlls->addWidgetDown(new ofxUILabel("\n\nPress \"F\" for full screen/window mode \n\nPress \"C\" to hide controls", OFX_UI_FONT_MEDIUM));
	helpLabel->setVisible(false);
    
    //1.5 - Add a drop down for file source select
    filesDropDown = fileControlls->addDropDownList("DATASETS", dataSource->getDataFiles(), 300);
    
    //1.6 - Add a couple of spacers to move the buttons down
    fileControlls->addSpacer(400, 500);
    
    //1.7 - Add a Preview, Update and Generate buttons
    fileControlls->addLabelButton("Preview", false);
    fileControlls->addLabelButton("Update", false);
    fileControlls->addLabelButton("Generate", false);
    
	//hook up the listener to the main controlls
	ofAddListener(fileControlls->newGUIEvent, this, &ofApp::fileControllsGuiEvent);
    
    
    //2.0 - Add a strategy canvas
    strategyControlls = new ofxUICanvas( FILE_CONTROL_WIDTH+20, 10, FILE_CONTROL_WIDTH, 60);
    
    //2.1 - Add a label
    strategyControlls->addWidgetDown(new ofxUILabel("Strategy control", OFX_UI_FONT_LARGE));

    //2.2 - Statically populate the strategies list
    strategies = new vector<string>();
    strategies->push_back("Full-cone");
    strategies->push_back("Association rules only");
    
    strategiesDropDown = strategyControlls->addDropDownList("STRATEGIES", *strategies, 300);
    
    //2.3 - Hook up a listener to the drop down
    ofAddListener(strategyControlls->newGUIEvent, this, &ofApp::shapeStrategyGuiEvent);
    

}

//--------------------------------------------------------------
void ofApp::fileControllsGuiEvent(ofxUIEventArgs &e)
{
    
    string name = e.widget->getName();
	int kind = e.widget->getKind();
	ofLog() << "got event from: " << name;

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
    string name = e.widget->getName();
	int kind = e.widget->getKind();
	
    
    if(name == "STRATEGIES")
    {
        ofxUIDropDownList *dropdown = (ofxUIDropDownList *) e.widget;
        
		vector<ofxUIWidget *> &selected = dropdown->getSelected();
        
        if (selected.size() > 0) {
            std::string selected_name = selected[0]->getName();
            
            if(selected_name.compare("Full-cone") == 0)
            {
                
                ofLog() << "New visualization strategy selected: " << selected_name;
                
                if(currentStrategyControlls != NULL)
                    currentStrategyControlls->ofxUICanvas::~ofxUICanvas();
                
                
                currentStrategy = new FullConeStrategy();
                currentStrategy->initializeStrategy(dataSource);
                currentStrategyControlls = currentStrategy->drawGui(currentStrategyControlls);
                
            }
            
            if (selected_name.compare("Association rules only") == 0)
            {
                
                ofLog() << "New visualization strategy selected: " << selected_name;
                
                if(currentStrategyControlls != NULL)
                    currentStrategyControlls->ofxUICanvas::~ofxUICanvas();
                
                
                currentStrategy = new AssociationCone();
                currentStrategy->initializeStrategy(dataSource);
                currentStrategyControlls = currentStrategy->drawGui(currentStrategyControlls);
                
            }
            
        }
        
        
    }
    

    
}
