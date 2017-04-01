//
//  Scene3.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/25.
//
//

#ifndef Scene3_h
#define Scene3_h

#include "ofMain.h"
#include "ofxAnimationPrimitives.h"

class Scene3 : public ofxAnimationPrimitives::Scene {
    
public:
    OFX_ANIMATION_PRIMITIVES_DEFINE_SCENE(Scene3);
    
    Scene3(){
        LM3.setup();
        init_layers3();
    }
    
    void update(){
        LM3.update();
    }
    
    void draw(){
        LM3.draw();
    }
    
};




#endif /* Scene3_h */
