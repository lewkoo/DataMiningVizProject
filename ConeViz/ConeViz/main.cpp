#include "ofAppGlutWindow.h"
#include "coneVizApp.h"

int main() {
	ofAppGlutWindow window;
	ofPoint screenSize = window.getScreenSize();
	ofSetupOpenGL(&window, screenSize.x, screenSize.y, OF_FULLSCREEN);
	ofRunApp(new coneVizApp());
}
