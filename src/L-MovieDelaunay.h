#ifndef L_MovieDelaunay_h
#define L_MovieDelaunay_h

#include "ofxLayer.h"
#include "Context.h"
#include "MovieDelaunay.h"

using namespace ofxLayer;
class MovieDelaunay : public ofxLayer::Layer {
    
public:
    
    OFX_LAYER_DEFINE_LAYER_CLASS(MovieDelaunay);
    
    Delaunays delauney;
    
    void setup(){
    }
    
    void update(){
        delauney.update();
    }
    
    void draw(){
        //ofBackground(255, 0, 0);
        delauney.draw();
    }
    
};




#endif /* L_MovieDelaunay_h */