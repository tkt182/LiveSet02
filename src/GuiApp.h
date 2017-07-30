#ifndef ofGuiApp
#define ofGuiApp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofApp.h"

class GuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofParameterGroup parameters;
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofxPanel gui;
    
    shared_ptr<ofApp> app;
};

#endif /* ofGuiApp */
