#ifndef MovieDelaunay_h
#define MovieDelaunay_h

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"

class Delaunays {
public:
    Delaunays();
    ~Delaunays();
    
    void init();
    void update();
    void draw();
    
    ofxCv::FlowPyrLK    flow;
    ofVideoPlayer 		movie;
    ofxDelaunay         delaunay;
    
    std::vector<ofVec3f> pts;
    
    //std::vector<ofP> triangleIndex;
    ofMesh                 triangleMesh;
    
    int count;
    
};


#endif /* MovieDelaunay_h */
