#ifndef MovieDelaunay_h
#define MovieDelaunay_h

#include "ofMain.h"
#include "ofxOpenCv.h"

class Delaunays {
public:
    Delaunays();
    ~Delaunays();
    
    void update();
    void draw();
    
    //ofxCv::FlowPyLK     flow;
    ofVideoPlayer 		movie;
    //ofxDelaunay         delaunay;
    
    
};


#endif /* MovieDelaunay_h */
