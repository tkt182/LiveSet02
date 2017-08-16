#ifndef MovieDelaunay_h
#define MovieDelaunay_h

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxDelaunay.h"
#include "ofxOpenCv.h"


#define FILTER_NUM 3

class Delaunays {
public:
    Delaunays();
    ~Delaunays();
    
    void init();
    void update();
    void draw();
    void setFilterId(int filterId);
    void setLowVal(float val);
    void setFlowResetVal(float val);
    
    ofxCv::FlowPyrLK     flow;
    ofxCv::FlowFarneback fbFlow;
 	ofxCv::Flow*         curFlow;
    
    ofVideoPlayer 		movie;
    ofVideoGrabber      videoCam, videoCamForFbFlow;
    ofxCvColorImage     colorImgs[FILTER_NUM];
    ofxDelaunay         delaunay;
    
    std::vector<ofVec3f> pts;
    
    //std::vector<ofP> triangleIndex;
    ofMesh                 triangleMesh;
    
    int   count;
    int   currentFilter;
    float lowVal;
    float flowResetVal;
    
    int windowWidth, windowHeight;
    
};


#endif /* MovieDelaunay_h */