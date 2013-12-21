#pragma once

#include "Level.h"
#include "Itemset.h"
#include "Utilities.h"
#include "ofMain.h"
#include "ofUI\ofxUI.h"
#include <math.h>

#define GUI_WIDTH 600
#define GUI_HEIGHT 300

using namespace std;

class coneVizApp : public ofBaseApp {

	private:
		std::vector<Itemset*> itemsets;
		std::vector<Level*> levels;

		int mouseX;
		int mouseY;

		bool refreshRequested;
		bool isItemsetSelected;
		bool renderAxis;

		//GUI canvas
		ofxUICanvas* mainGUI;
		ofxUILabel*  helpLabel;
		ofxUIDropDownList* filesDropDown;


		//Dataset files variables
		ofFile currentDataset;
		vector< ofFile > datasetFiles;
		vector< string > datasetFileNames;
		int numFiles; // total number of dataset files


		//Methods
		void setUpGUI(); //     this sets up the ofxUI GUI
		void scanForFiles(); // this scans the data folder for dataset files
		void refreshViz(); //reloads and resets the visualization 

	public:
	
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
	
		void drawInteractionArea();
		void drawAxis();

		void guiEvent(ofxUIEventArgs &e);

		bool bShowHelp;
		ofEasyCam cam; // add mouse controls for camera movement
		ofMesh	  mesh;	
};
