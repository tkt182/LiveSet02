#include "RaiseParticles.h"

RaiseParticles::RaiseParticles(){
    
    billboards.setUsage(GL_DYNAMIC_DRAW);
    billboards.setMode(OF_PRIMITIVE_POINTS);
    
    maxParticles = 10000;
    numParticles = 0;
    
    swidth = ofGetWidth()*4;
    sheight = ofGetHeight();
    sdepth = ofGetWidth()*4;
    
    // Easing
    //now      = -10000.f;
    initTime = 0.f;
    //initTime = ofGetElapsedTimef();
    initTime = 10000.f;
    endPosition = sheight;
    isMove = false;
    finishMove = false;
    
    for(int i = 0; i < 10000; i++){
        ofVec3f pos = ofVec3f(
            ofRandom(-swidth, swidth),
            //ofRandom(-sheight, sheight),
            -sheight + ofRandom(-100, 100),
            ofRandom(-sdepth, sdepth)
        );
    
        positions.push_back(pos);
        billboards.addVertex(ofVec3f(positions[i].x, positions[i].y, positions[i].z));

        float y = -sheight + ofRandom(-500, 500);
        initY.push_back(y);
        endY.push_back(y + endPosition * 2.0);
        numParticles++;
    }
    
}

RaiseParticles::~RaiseParticles(){
    
}

void RaiseParticles::update(){
    
    
    float duration = 5.f;
    float endTime = initTime + duration;
    float now = ofGetElapsedTimef();
    float tmpY;
    
    for(int i = 0; i < positions.size(); i++){
        ofVec3f pos = positions[i];
        positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, initY[i], endY[i], &ofxeasing::linear::easeIn);
        //positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, -sheight, endPosition, &ofxeasing::linear::easeIn);
        //positions[i].y = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::linear::easeIn);

        if(i == 0){
            tmpY = positions[0].y;
        }
        //if(positions[i].y < tmpY){
        //    tmpY = positions[i].y;
        //}
        billboards.getVertices()[i].set(pos);
    }
    
    if(tmpY < endY[0] && initTime < 10000){
        isMove = true;
    }else{
        isMove = false;
    }
    
    if(tmpY >= endY[0]){
        finishMove = true;
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
