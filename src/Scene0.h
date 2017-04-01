//
//  Scene0.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/24.
//
//

#ifndef Scene0_h
#define Scene0_h

#include "ofMain.h"
#include "ofxAnimationPrimitives.h"

#include "Layers.h"

class Scene0 : public ofxAnimationPrimitives::Scene {

public:
    OFX_ANIMATION_PRIMITIVES_DEFINE_SCENE(Scene0);
    
    Scene0(){
        LM0.setup(ofGetWidth(), ofGetHeight());
        init_layers();
        
        
    }
    
    void update(){
        LM0.update();
        
    }
    
    void draw(){
        //cout << "Scene0: " << endl;
        //ofBackground(0);
        //ofSetColor(255);
        //ofDrawSphere(10);
        LM0.draw();
    }
    
    void viewWillAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewWillDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    
};

#endif /* Scene0_h */
