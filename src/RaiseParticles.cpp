#include "RaiseParticles.h"

RaiseParticles::RaiseParticles(){
    
    billboards.setUsage(GL_DYNAMIC_DRAW);
    billboards.setMode(OF_PRIMITIVE_POINTS);
    
    maxParticles = 1000;
    numParticles = 0;
    
    swidth = ofGetWidth()*4;
    sheight = ofGetHeight();
    sdepth = ofGetWidth()*4;
    
    // Easing
    //now      = -10000.f;
    initTime = 0.f;
    initTime = ofGetElapsedTimef();
    //initTime = 10000.f;
    endPosition = sheight;
    isMove      = false;
    finishMove  = false;
    addNextFlag = false;
    displayFlag = false;
    
    for(int i = 0; i < 1000; i++){
        ofVec3f pos = ofVec3f(
            ofRandom(-swidth, swidth),
            //ofRandom(-sheight, sheight),
            -sheight + ofRandom(-100, 100),
            ofRandom(-sdepth, sdepth)
        );

        float y = -sheight * 2.0 + ofRandom(-500, 500);
        initY.push_back(y);
        endY.push_back(y + endPosition * 4.0);
        
        float z = ofRandom(-1500, 0);
        initZ.push_back(z);
        endZ.push_back(z + sdepth *1.7  / 4.0);
        
        pos.y = y;
        pos.z = z;
        
        positions.push_back(pos);
        billboards.addVertex(ofVec3f(positions[i].x, positions[i].y, positions[i].z));

        numParticles++;
    }
    
}

RaiseParticles::~RaiseParticles(){
    
}

void RaiseParticles::update(){
    float duration = 10.f;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    float tmpY;
    
    for(int i = 0; i < positions.size(); i++){
        
        ofVec3f pos = positions[i];
        positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, initY[i], endY[i], &ofxeasing::linear::easeIn);
        positions[i].z = ofxeasing::map_clamp(now, initTime, endTime, initZ[i], endZ[i], &ofxeasing::linear::easeIn);
        
        if(i == 0){
            
            tmpY = positions[i].y;
            if(tmpY - initY[i] > (endY[i] - initY[i]) / 4.0){
                this->addNextFlag = true;
            }
        }
        
        billboards.getVertices()[i].set(pos);
        
    }
    
}

void RaiseParticles::draw(){
    billboards.draw();
}

void RaiseParticles::setCurrentTime(){
    //now      = ofGetElapsedTimef();
    initTime = ofGetElapsedTimef();
}

bool RaiseParticles::getMoveStatus(){
    return isMove;
}

bool RaiseParticles::getFinishMove(){
    return finishMove;
}

bool RaiseParticles::getAddNextFlag(){
    return addNextFlag;
}

void RaiseParticles::enableDisplay(){
    displayFlag = true;
}
