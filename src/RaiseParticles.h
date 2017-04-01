//
//  RaiseParticles.h
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/06.
//
//

#ifndef RaiseParticles_h
#define RaiseParticles_h

#include "ofMain.h"
#include "ofxEasing.h"
//#include "ofxTween.h"

class RaiseParticles {
public:
    RaiseParticles();
    ~RaiseParticles();
    
    void update();
    void draw();
    void setCurrentTime();
    bool getMoveStatus();
    bool getFinishMove();
    
    int numParticles;
    int maxParticles;
    int swidth, sheight, sdepth;
    
    deque<ofVec3f> positions;
    deque<float> initY;
    deque<float> endY;
    deque<float> movePosition;
    float now;
    float initTime;
    float endPosition;
    
    bool isMove;
    bool finishMove;
    GLfloat defaultDistance[3];
    ofVboMesh billboards;
    
};


#endif /* RaiseParticles_h */
