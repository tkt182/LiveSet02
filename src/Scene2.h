//
//  Scene2.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/18.
//
//

#ifndef Scene2_h
#define Scene2_h

#include "ofMain.h"
#include "ofxAnimationPrimitives.h"

//#include "Layers.h"

class Scene2 : public ofxAnimationPrimitives::Scene {
    
public:
    OFX_ANIMATION_PRIMITIVES_DEFINE_SCENE(Scene2);
    
    Scene2(){
        LM2.setup(ofGetWidth(), ofGetHeight());
        init_layers2();
    }
    
    void update(){
        LM2.update();
    }
    
    void draw(){
        LM2.draw();
    }
    
    void viewWillAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewWillDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    
};

#endif /* Scene2_h */