//
//  Scene1.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/24.
//
//

#ifndef Scene1_h
#define Scene1_h

#include "ofMain.h"
#include "ofxAnimationPrimitives.h"

//#include "Layers.h"

class Scene1 : public ofxAnimationPrimitives::Scene {
    
public:
    OFX_ANIMATION_PRIMITIVES_DEFINE_SCENE(Scene1);
    
    Scene1(){
        cout << "Scene1: " << endl;
        LM1.setup(ofGetWidth(), ofGetHeight());
        init_layers1();
    }
    
    void update(){
        LM1.update();
    }
    
    void draw(){
        LM1.draw();
    }
    
    void viewWillAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidAppear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewWillDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    void viewDidDisappear() { cout << __PRETTY_FUNCTION__ << endl; }
    
};


#endif /* Scene1_h */
