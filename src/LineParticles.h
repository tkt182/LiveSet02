//
//  LineParticles.hpp
//  LiveSet01
//
//  Created by 高田 信一郎 on 2017/01/25.
//
//

#ifndef LineParticles_h
#define LineParticles_h

#define SPHERE 1
#define BOX 2

#include "ofMain.h"


class LineParticles {
    
public:
    LineParticles();
    ~LineParticles();
    
    void update();
    void draw();
    void resetParticlePosition();
    void changeMorphTarget();
    void changeMorphForce();
    void changeTargetForce();
    void increaseMinDistance(float d);
    void setMinDistance(float d);
    
    int morphTargetId;
    int circleResolution;
    int slides;
    int radius;
    int particleNum;
    bool isMorphing;
    bool forceMorph;
    bool disableMorph;
    bool forceTarget;
    int counter;
    int startMorphAt;
    int frames;
    float lineMinDistance;
    float rotateX;
    float rotateY;
    float rotateZ;
    
    
    vector<ofVec3f> spherePoints;
    vector<ofVec3f> boxPoints;
    
    vector<ofVec3f> particlePoints;
    vector<ofVec3f> linePoints;
    vector<ofFloatColor> linePointColors;
    
    vector<ofVec3f> morphTarget;
    
    ofVboMesh renderedGeom;
    ofVboMesh renderedLineGeom;
    ofVboMesh sphereGeom;
    ofVboMesh sphereLineGeom;
    ofVboMesh boxGeom;
    
    typedef struct{
        int numConnections;
        ofVec3f velocity;
    } tPData;
    
    vector<tPData> particlesData;
    
    
};


#endif /* LineParticles_h */
