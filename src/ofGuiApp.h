#ifndef ofGuiApp
#define ofGuiApp

#include "ofMain.h"
#include "ofxGui.h"

class ofGuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ofParameterGroup parameters;
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofxPanel gui;
};

#endif /* ofGuiApp */
