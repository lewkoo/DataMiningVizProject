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

		//Set up the GUI
		setUpGUI();

		renderAxis = false;

        //PROCESS THE DATASETS
		scanForFiles(); // populate the combo box with data file names

        itemsets = std::vector<Itemset*>();
		levels = std::vector<Level*>();

		Utilities::loadItemsets(currentDataset, &itemsets, &levels);

		Utilities::setYCoordinates(&levels, Utilities::SHAPE_TYPES::NORMAL_CONE); // goes over all the levels and sets the Y coordinates

		for(int i = 0; i < levels.size(); i++)
		{
			levels[i]->calculateItemsetLocations();
		}

		for(int i = 0; i < itemsets.size(); i++)
		{
			mesh.addVertex(itemsets[i]->getLocation());
		}

}

//--------------------------------------------------------------
void coneVizApp::update(){
        
}

//--------------------------------------------------------------
void coneVizApp::draw(){
    
	ofBackgroundGradient(ofColor(64), ofColor(0));

    cam.begin();                

    drawAxis();
        
	ofSetColor(ofColor::gray);
	
	glPointSize(6);
	ofSetColor(ofColor::white);
	mesh.drawVertices();

	for(int i = 0; i < levels.size(); i ++)
	{
		this->levels[i]->drawItemsets();
	}

	for(int i = 0; i < levels.size()-1; i++)
	{
		Utilities::drawConnections(*levels[i], *levels[i+1]);
	}

	cam.end();




    //drawInteractionArea();
    ofSetColor(255);

	int num_itemsets = mesh.getNumVertices();
	float nearestDistance = 0;
	ofVec2f nearestVertex;
	int nearestIndex;
	ofVec2f mouse(mouseX, mouseY);

	for(int i = 0; i < num_itemsets; i++) {
		ofVec3f cur = cam.worldToScreen(mesh.getVertex(i));
		float distance = cur.distance(mouse);
		if(i == 0 || distance < nearestDistance) {
			nearestDistance = distance;
			nearestVertex = cur;
			nearestIndex = i;
		}
	}


	
	ofSetColor(ofColor::gray);
	ofLine(nearestVertex, mouse);
	
	ofNoFill();
	ofSetColor(ofColor::yellow);
	ofSetLineWidth(2);
	ofCircle(nearestVertex, 4);
	ofSetLineWidth(1);
	
	ofVec2f offset(10, -10);
	ofDrawBitmapStringHighlight(ofToString(nearestIndex), mouse + offset);


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

	if(isItemsetSelected)
		ofDrawBitmapStringHighlight("Itemset selected!", 10, 150);


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
	if(!renderAxis)
		return;

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
						if(helpLabel->isVisible()){ 
							helpLabel->setVisible(false);
							filesDropDown->setVisible(true);
						}
						else{ 
							helpLabel->setVisible(true);
							filesDropDown->setVisible(false);
						}

                        break;
				case 'A':
				case 'a':
						renderAxis = !renderAxis;
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
void coneVizApp::dragEvent(ofDragInfo dragInfo)
{ 
        
}            

void coneVizApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	cout << "got event from: " << name << endl; 	
	
	if(name == "DATASETS") //catch an event from the drop down
	{
		ofxUIDropDownList *dropdown = (ofxUIDropDownList *) e.widget; 

		vector<ofxUIWidget *> &selected = dropdown->getSelected(); 

        if (selected.size() > 0)
        {
			std::string selected_name = selected[0]->getName();

			for(int i = 0; i < datasetFiles.size(); i++)
			{
				if(selected_name.compare(datasetFiles[i].getBaseName()) == 0)
				{
					currentDataset = datasetFiles[i];
					Utilities::loadItemsets(currentDataset, &itemsets, &levels);
				}
			}

		}

	}

}


void coneVizApp::setUpGUI()
{

	mainGUI = new ofxUICanvas( 30, ofGetScreenHeight()-GUI_HEIGHT, GUI_WIDTH, GUI_HEIGHT);
	mainGUI->addWidgetDown(new ofxUILabel("ConeViz Visualization Tool", OFX_UI_FONT_LARGE)); 
	mainGUI->addWidgetEastOf(new ofxUILabel("     * press 'h' for help & controls", OFX_UI_FONT_MEDIUM), "ConeViz Visualization Tool", false);

	helpLabel = mainGUI->addLabel("Help & Controls", "\n\n\nPress \"F\" for full screen/window mode \n\nPress \"M\" and drag the mouse to shift the centre of the shape \n\nPress \"C\" to turn off the camera interactions \n\nPress \"A\" to turn axis rendering on/off");
	helpLabel->setVisible(false);

	//hook up the listener
	ofAddListener(mainGUI->newGUIEvent, this, &coneVizApp::guiEvent); 
	
}

void coneVizApp::scanForFiles()
{
	ofDirectory dataDirectory = ofDirectory("datasets/");

	cout << "SETUP: Reading datasets from : " << dataDirectory.getAbsolutePath() << endl;
	
	if(dataDirectory.exists() == false)
		cout << "SETUP: FATAL ERROR! Data directory does not exist in " << dataDirectory.getOriginalDirectory() << endl;

	// filter the directory listing for txt files, ignore anything else
	dataDirectory.allowExt("txt"); 

	numFiles = dataDirectory.listDir();

	cout << "SETUP: Total number of dataset files found: " << numFiles << endl;

	//load the files
	datasetFiles = dataDirectory.getFiles();

	//load the filenames
	for(int i = 0; i < datasetFiles.size(); i++)
	{
		datasetFileNames.push_back(datasetFiles[i].getBaseName());
		cout << "SETUP: Loading the file: " << datasetFileNames[i] << endl;
	}

	//set up the current file pointer
	currentDataset = datasetFiles[0];

	//Add the drop down GUI
	filesDropDown = mainGUI->addDropDownList("DATASETS", datasetFileNames, 200);
}