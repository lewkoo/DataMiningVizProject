#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "DataParser.h"

#define GUI_WIDTH 400
#define GUI_HEIGHT 700

class ofApp : public ofBaseApp{
    
    private:
    
        DataParser* dataSource;
        int counter;
    
        //GUI elements
        ofxUICanvas* fileControlls;
        ofxUIWidget*  helpLabel;
        ofxUIDropDownList* filesDropDown;
    

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
    
        //GUI set up
        void setUpGUI();
    
        //GUI event listeners
        void fileControllsGuiEvent(ofxUIEventArgs &e);
		void shapeStrategyGuiEvent(ofxUIEventArgs &e);
    
    
};
