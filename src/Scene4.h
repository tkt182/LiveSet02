//
//  Scene4.h
//  LiveSet02
//
//  Created by 高田 信一郎 on 2017/04/16.
//
//

#ifndef Scene4_h
#define Scene4_h

#include "ofMain.h"
#include "ofxAnimationPrimitives.h"

class Scene4 : public ofxAnimationPrimitives::Scene {
    
public:
    OFX_ANIMATION_PRIMITIVES_DEFINE_SCENE(Scene4);
    
    Scene4(){
        LM4.setup();
        init_layers4();
    }
    
    void update(){
        LM4.update();
    }
    
    void draw(){
        LM4.draw();
    }
    
};

#endif /* Scene4_h */
