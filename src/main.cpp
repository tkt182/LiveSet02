#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

    //ofSetupOpenGL(1024,768,OF_FULLSCREEN);
    //ofSetWindowPosition(1441,0);
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	//ofRunApp(new ofApp());
    
    ofGLFWWindowSettings settings;

    settings.width = 1280;
    settings.height = 720;
    settings.setPosition(ofVec2f(600, 0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 640;
    settings.height = 360;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->gui = guiApp;
    
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
