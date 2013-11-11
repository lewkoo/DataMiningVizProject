#pragma once

#include "Level.h"
#include "Itemset.h"
#include "Utilities.h"
#include "ofMain.h"
#include <math.h>

using namespace std;

class coneVizApp : public ofBaseApp {

	private:
		std::vector<Itemset*> itemsets;
		std::vector<Level*> levels;


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
		bool bShowHelp;
		ofEasyCam cam; // add mouse controls for camera movement
};
