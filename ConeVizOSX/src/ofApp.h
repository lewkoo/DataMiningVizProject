#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "DataParser.h"
#include "Strategy.h"
#include "FullConeStrategy.h"
#include "AssociationCone.h"

#define FILE_CONTROL_WIDTH 400
#define FILE_CONTROL_HEIGHT 700

class ofApp : public ofBaseApp{
    
    private:
    
        DataParser* dataSource;
    
        Strategy* currentStrategy;
    
    
        //GUI elements
        ofxUICanvas* fileControlls;
        ofxUIWidget*  helpLabel;
        ofxUIDropDownList* filesDropDown;
    
    
        ofxUICanvas* strategyControlls;
        ofxUIDropDownList* strategiesDropDown;
        vector<string>* strategies;
    
        //This canvas gets passed to the strategy,
        //which then defines its own GUI
        ofxUICanvas* currentStrategyControlls;
    
    
    

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
    
        //Parser set up
        void setUpParser();
        void changeFileSource(int indexOfFileToLoad=0);
        //file index in the drop-down menu
    
        //GUI set up
        void setUpGUI();
    
        //GUI event listeners
        void fileControllsGuiEvent(ofxUIEventArgs &e);
		void shapeStrategyGuiEvent(ofxUIEventArgs &e);
    
    
};
