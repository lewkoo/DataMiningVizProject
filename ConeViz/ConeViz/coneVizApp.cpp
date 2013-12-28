#include "coneVizApp.h"


//--------------------------------------------------------------
void coneVizApp::setup(){
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
void coneVizApp::update(){

	refreshViz();
}

//--------------------------------------------------------------
void coneVizApp::draw(){
    
	//ofBackgroundGradient(ofColor(64), ofColor(0));

    cam.begin(); 
	

    drawAxis();
	ofSetColor(ofColor::gray);
	glPointSize(6);
	ofSetColor(ofColor::white);
	
	//Draw Lines
	mesh.setMode(OF_PRIMITIVE_LINES);
	mesh.draw();

	//Draw the spheres
	for(int i = 0; i < levels.size(); i ++)
	{
		this->levels[i]->drawItemsets();
	}
	cam.end();
    drawInteractionArea();
    ofSetColor(255);

	
	//Locate the sphere that is closest to the mouse cursor
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
	

	//Draw the line between the current itemset + the data about it
	currentlySelectedSphere->setSelected(false);
	currentlySelectedSphere = spheres.at(nearestIndex);
	currentlySelectedSphere->setSelected(true);



	ofSetColor(ofColor::gray);
	ofLine(nearestVertex, mouse);
	
	ofNoFill();
	//ofSetColor(ofColor::yellow);
	//ofSetLineWidth(2);
	//ofCircle(nearestVertex, 4);
	//ofSetLineWidth(1);
	
	ofVec2f offset(10, -10);

	ofDrawBitmapStringHighlight(currentlySelectedSphere->getType() + "\n" + ofToString(currentlySelectedSphere->getFrequency()) + "\n" + currentlySelectedSphere->getName(), mouse + offset);
	//ofDrawBitmapStringHighlight(ofToString(nearestIndex), mouse + offset);

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
							shapeHeightSlider->setVisible(true);
							clusteringBoundarySlider->setVisible(true);
							frequencyLineThreshold->setVisible(true);
							lineCalculation->setVisible(true);
						}
						else{ 
							helpLabel->setVisible(true);
							filesDropDown->setVisible(false);
							shapeHeightSlider->setVisible(false);
							clusteringBoundarySlider->setVisible(false);
							frequencyLineThreshold->setVisible(false);
							lineCalculation->setVisible(false);
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
	ofVec2f mouse(mouseX, mouseY);
	ofVec3f cur = cam.worldToScreen(currentlySelectedSphere->getLocation());

	float distance = cur.distance(mouse);
	
	if(distance <= currentlySelectedSphere->getRadius()){
		
		//1 - Determine if it is an itemset or a cluster

		if(currentlySelectedSphere->getType() == "Itemset")
		{
			//just use it to determine your path
			currentlySelectedItemset = dynamic_cast<Itemset*>(currentlySelectedSphere);
		}else //we have a cluster. Build a GUI, make is visible, wait for an event... 
		{
			
		}
		
	}
		

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

void coneVizApp::refreshViz()
{

	if(refreshRequested == false)
		return;

	itemsets = std::vector<Itemset*>();
	levels = std::vector<Level*>();
	spheres = std::vector<VizElement*>();
	mesh = ofMesh();
	mesh.clearIndices();
	mesh.clear();

	Utilities::loadItemsets(currentDataset, &itemsets, &levels);

	Utilities::setYCoordinates(&levels, Utilities::SHAPE_TYPES::NORMAL_CONE); // goes over all the levels and sets the Y coordinates

	Level::setClusteringFactor(20);

	//finding the max frequency in the dataset
	maxFrequency = Utilities::findMaxFreq(&levels);

	//color coding
	ofColor green(0,255,0);
	ofColor red(255,0,0);

	for(int i = 0; i < levels.size(); i++)
	{
		levels[i]->calculateItemsetLocations();

		std::vector<VizElement*> elements = levels[i]->getVizElements();

		for(int j = 0; j < elements.size(); j++)
		{
			
			mesh.addVertex(elements[j]->getLocation());
			elements[j]->setMeshID(mesh.getNumVertices()-1);
			spheres.push_back(elements[j]);

			float colorPercent = (float)elements[j]->getFrequency() / (float)maxFrequency;
			colorPercent = ofClamp(colorPercent, 0, 1);

			elements[j]->setColor(green.getLerped(red, colorPercent));
		}

	}

	if(calculateLines)
	{
		for(int i = 0; i < levels.size()-1; i++)
		{
			Utilities::setConnections(*levels[i], *levels[i+1], &mesh, lineFrequencyThreshold);
		}
	}

	//set the flag to false, just do rendering from now on
	refreshRequested = false;

	currentlySelectedSphere = new Itemset();

	if(frequencyLineThreshold != NULL)
		frequencyLineThreshold->setMax(maxFrequency);


}

void coneVizApp::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	//cout << "got event from: " << name << endl; 	
	
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
					refreshRequested = true;

				}
			}

		}

	}
	
	else if(name == "Shape height")
	{
	
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		Utilities::setYRasingFactor(slider->getValue()*1000);
		refreshRequested = true;	
	}

	else if(name == "Line drawing threshold")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		lineFrequencyThreshold = slider->getValue()*maxFrequency;
		refreshRequested = true;
	}

	else if(name == "Clustering factor")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		Level::setClusteringFactor(slider->getValue()*100);
		refreshRequested = true;
	}

	else if(name == "Clustering boundary")
	{
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		Level::setClusteringBoundary(slider->getValue()*1000);
		refreshRequested = true;
	}

	else if(name == "Turn off connections calculation (use when loading large datasets)")
	{
		calculateLines = !calculateLines;
	}

}


void coneVizApp::setUpGUI()
{

	mainGUI = new ofxUICanvas( 30, ofGetScreenHeight()-GUI_HEIGHT, GUI_WIDTH, GUI_HEIGHT);
	mainGUI->addWidgetDown(new ofxUILabel("ConeViz Visualization Tool", OFX_UI_FONT_LARGE)); 
	mainGUI->addWidgetEastOf(new ofxUILabel("     * press 'h' for help & controls", OFX_UI_FONT_MEDIUM), "ConeViz Visualization Tool", false);

	helpLabel = mainGUI->addLabel("Help & Controls", "\n\n\nPress \"F\" for full screen/window mode \n\nPress \"M\" and drag the mouse to shift the centre of the shape \n\nPress \"C\" to turn off the camera interactions \n\nPress \"A\" to turn axis rendering on/off");
	helpLabel->setVisible(false);

	shapeHeightSlider = mainGUI->addSlider("Shape height", 0, 1000, DEFAULT_SHAPE_HEIGHT, 500, 10);

	frequencyLineThreshold = mainGUI->addSlider("Line drawing threshold", 1, maxFrequency, 1, 500, 10);

	clusteringBoundarySlider = mainGUI->addSlider("Clustering boundary", 1, 1000, 1, 500, 10);

	lineCalculation = mainGUI->addToggle( "Turn off connections calculation (use when loading large datasets)", false, 10, 10);

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