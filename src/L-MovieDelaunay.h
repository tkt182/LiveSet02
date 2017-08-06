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
        delauney.init();
    }
    
    void update(){
        keyEvent();
        delauney.update();
    }
    
    void draw(){
        //ofBackground(255, 0, 0);
        delauney.draw();
    }
    
    void viewWillAppear() { cout << "Movie Will Start" << endl; }
    void viewDidDisappear() { cout << "Movie Stopped" << endl; }

private:
    
    void keyEvent(){
        int key = $Context(KeyboardControl)->getPressedKey();
        if (key == 'v'){
            delauney.setFilterId(0);
        }
        if (key == 'b'){
            delauney.setFilterId(1);
        }
    
    }


};




#endif /* L_MovieDelaunay_h */