#include "ofApp.h"
#include "Scenes.h"
#include "Context.h"


void ofApp::switchScene(int &temp){
    if(temp == 0) SM.changeScene<Scene0>();
    if(temp == 1) SM.changeScene<Scene1>();
    if(temp == 2) SM.changeScene<Scene2>();
    
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofHideCursor();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);

    
    init_context();
    $Context(KeyboardControl)->setup();
    
    SM.addScene<Scene0>();
    SM.addScene<Scene1>();
    SM.addScene<Scene2>();
    SM.addScene<Scene3>();
    
    SM.changeScene("Scene0");
    
    finalFbo.allocate(ofGetWidth(), ofGetHeight());
    myGlitch.setup(&finalFbo);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    SM.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    finalFbo.begin();
    ofClear(0, 0, 0, 255);
    SM.draw();
    finalFbo.end();
    
    /* Apply effects */
    myGlitch.generateFx();
    
    /* draw effected view */
    finalFbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == '1') SM.changeScene<Scene0>();
    if (key == '2') SM.changeScene<Scene1>();
    if (key == '3') SM.changeScene<Scene2>();
    if (key == '4') SM.changeScene<Scene3>();
    
    $Context(KeyboardControl)->setPressedKey(key);
    
    if (key == 'q') myGlitch.toggleFx(OFXPOSTGLITCH_CONVERGENCE);
    if (key == 'w') myGlitch.toggleFx(OFXPOSTGLITCH_GLOW);
    if (key == 'e') myGlitch.toggleFx(OFXPOSTGLITCH_SHAKER);
    if (key == 'r') myGlitch.toggleFx(OFXPOSTGLITCH_CUTSLIDER);
    if (key == 't') myGlitch.toggleFx(OFXPOSTGLITCH_TWIST);
    if (key == 'y') myGlitch.toggleFx(OFXPOSTGLITCH_OUTLINE);
    if (key == 'u') myGlitch.toggleFx(OFXPOSTGLITCH_NOISE);
    if (key == 'i') myGlitch.toggleFx(OFXPOSTGLITCH_SLITSCAN);
    if (key == 'o') myGlitch.toggleFx(OFXPOSTGLITCH_SWELL);
    //if (key == 'p') myGlitch.toggleFx(OFXPOSTGLITCH_INVERT);
    //if (key == 'p') myGlitch.toggleFx(OFXPOSTGLITCH_CR_RLINE);
    if (key == 'p') myGlitch.toggleFx(OFXPOSTGLITCH_CR_MIRROR4);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    $Context(KeyboardControl)->setPressedKey(0);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
