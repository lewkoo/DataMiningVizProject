#include "ofAppGlutWindow.h"
#include "coneVizApp.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 640, 480, OF_FULLSCREEN);
	ofRunApp(new coneVizApp());
}
