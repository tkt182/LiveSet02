//
//  Context.h
//  SceneBase
//
//  Created by 高田 信一郎 on 2016/12/18.
//
//

#ifndef Context_h
#define Context_h

#include "ofxGlobalContext.h"
#include "ofxRollingCam.h"
#include "ofxProcessFFT.h"

class KeyboardControl : public ofxGlobalContext::Context {

public:
    int pressedKey;
    
    void setup(){
        pressedKey = -1;
    }
    
    void setPressedKey(int key){
        pressedKey = key;
    }
    
    int getPressedKey(){
        return pressedKey;
    }

};

class RollCam : public ofxGlobalContext::Context {

public:
    ofxRollingCam rollCam;
    
    void setup(){
        rollCam.setup();
        rollCam.setCamSpeed(0.1);
    }
    
    void update(){
        rollCam.update();
    }
    
    void begin(){
        rollCam.begin();
    }
    
    void end(){
        rollCam.end();
    }
    
    void setRandomPos(){
        rollCam.setRandomPos(270);
    }
    
    void setRandomScale(){
        rollCam.setRandomScale(1.0, 10.0);
    }
    
    void setDefaultScale(){
        rollCam.setScale(1.0);
    }
    
    ofVec3f getPosS(){
        rollCam.getPosS();
    }
    
    ofVec3f getPosN(){
        rollCam.getPosN();
    }
};

class AudioInput : public ofxGlobalContext::Context {

public:
    ProcessFFT fft;
    bool       disableAudio;
    
    void setup(){
        disableAudio = true;
        fft.setup();
    }
    
    void update(){
        fft.update();
    }
    
    float getLowValForEffect(){
        float lowVal = fft.getLowVal();
        if(disableAudio){
            //lowVal = ofRandom(0.0, 1.0);
            lowVal = 0.0;
        }
        
        return lowVal;
    }
    
    void changeDisableAudioFlag(){
        cout << "AUDIO FLAG : " << disableAudio << endl;
        disableAudio = !disableAudio;
    }
    
};


void init_context(){
    ofxGlobalContext::Manager::defaultManager().createContext<KeyboardControl>();
    ofxGlobalContext::Manager::defaultManager().createContext<RollCam>();
    ofxGlobalContext::Manager::defaultManager().createContext<AudioInput>();
}


#endif /* Context_h */
