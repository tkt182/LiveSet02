//
//  L-ParticleSystem.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/17.
//
//

#ifndef L_ParticleSystem_h
#define L_ParticleSystem_h

#include "ofxLayer.h"
#include "ParticleSystem.h"
#include "Context.h"

using namespace ofxLayer;
class ParticleSimulation : public ofxLayer::Layer {

public:

    OFX_LAYER_DEFINE_LAYER_CLASS(ParticleSimulation);
    
    ParticleSystem particles;
    
    void setup(){
        particles.setup();
    }
    
    void update(){
        setGLParam();
        keyEvent();
        $Context(RollCam)->update();
    }
    
    void draw(){
        ofBackground(255);
        //ofBackground(0);
        
        $Context(RollCam)->begin();
        ofPushMatrix();
        {
            particles.draw();
        }
        ofPopMatrix();
        $Context(RollCam)->end();
        
    }

private:
    
    void setGLParam(){
        static GLfloat distance[] = { 1.0, 0.0, 0.0 };
        //static GLfloat distance[] = { 0.0, 0.0, 1.0 };
        glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
        ofDisableArbTex();
        //ofEnableNormalizedTexCoords();
        //ofEnablePointSprites();
        //glAlphaFunc(GL_GEQUAL, 0.5);
        //glEnable(GL_ALPHA_TEST);
        glPointSize(10.0);
        //ofDisableAlphaBlending();
    }
    
    
    void keyEvent(){
        
        int key = $Context(KeyboardControl)->getPressedKey();
        if (key == 'z') {
            $Context(RollCam)->setRandomPos();
        }
        if (key == 'x') {
            $Context(RollCam)->setRandomScale();
        }
        if (key == 'c') {
            $Context(RollCam)->setDefaultScale();
        }
    }
    

};


#endif /* L_ParticleSystem_h */
