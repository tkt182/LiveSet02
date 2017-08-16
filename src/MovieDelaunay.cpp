#include "MovieDelaunay.h"

Delaunays::Delaunays(){
    flow.resetFlow();
    
    count        = 0;
    lowVal       = 0.0f;
    flowResetVal = 25.0f;
    
    windowWidth  = ofGetWidth();
    windowHeight = ofGetHeight();
}

Delaunays::~Delaunays(){
}

void Delaunays::init(){
    cout << "START" << endl;
    currentFilter = 0;
    //movie.load("movies/dancing.mp4");
    //movie.setLoopState(OF_LOOP_NORMAL);
    //movie.play();
    videoCam.initGrabber(ofGetWidth(), ofGetHeight());
    videoCamForFbFlow.setup(320, 240);
    videoCam.setDeviceID(2);
    videoCamForFbFlow.setDeviceID(2);
    
    // allocate buffer to filter
    for(int i = 0; i < FILTER_NUM; i++){
        colorImgs[i].allocate(ofGetWidth(), ofGetHeight());
    }
    
    curFlow = &fbFlow;
}


void Delaunays::update(){
    //movie.play();
    //movie.update();
    //flow.calcOpticalFlow(movie.getPixelsRef());
    videoCam.update();
    videoCamForFbFlow.update();
    
    for(int i = 0; i < FILTER_NUM; i++){
        colorImgs[i].setFromPixels(videoCam.getPixelsRef(), ofGetWidth(), ofGetHeight());
        
        switch (i) {
            // fullsize
            case 0:
                colorImgs[i].setROI(0, 0, ofGetWidth(), ofGetHeight());
                break;
            
            // left top
            case 1:
                colorImgs[i].setROI(0, 0, ofGetWidth() / 2, ofGetHeight() / 2);
                break;
            // bottom
            case 2:
                colorImgs[i].setROI(0, ofGetHeight() / 2, ofGetWidth(), ofGetHeight() / 2);
                
                
            default:
                break;
        }
    }
    
    fbFlow.setPyramidScale(0.5);
    fbFlow.setNumLevels(2);
    fbFlow.setWindowSize(8);
    fbFlow.setNumIterations(2);
    fbFlow.setPolyN(7);
    fbFlow.setPolySigma(1.5);
    fbFlow.setUseGaussian(false);
    curFlow->calcOpticalFlow(videoCamForFbFlow);
    
    flow.calcOpticalFlow(videoCam.getPixelsRef());

    
    triangleMesh.clear();
    pts.clear();
    pts = flow.getFeatures();
    
    delaunay.reset();
    if (pts.size() > 15){
        for (int i = 0; i < pts.size(); i+=5){
            delaunay.addPoint(pts[i]);
        }
        delaunay.triangulate();
    }
    
    //movie.update();

    if(lowVal > flowResetVal){
        flow.resetFeaturesToTrack();
    }
    
    count++;
    
    int triangleNum = delaunay.getNumTriangles();
    for(int i = 0; i < triangleNum; i++){
        if(i % 25 == 0){
            ITRIANGLE index = delaunay.getTriangleAtIndex(i);
            vector<ofPoint> trianglePoints = delaunay.getPointsForITriangle(index);
        
            for(int j = 0; j < trianglePoints.size(); j++){
                triangleMesh.addVertex(trianglePoints[j]);
                triangleMesh.addColor(ofColor(255));
                //triangleMesh.addColor(ofColor(ofRandom(255), ofRandom(255), ofRandom(255)));
            }
        }
    }
    
}

void Delaunays::draw(){
    g
    ofSetColor(255);
    //movie.draw(0,0);
    ofNoFill();
    delaunay.draw();
    ofFill();
    triangleMesh.draw();
    curFlow->draw(0, 0, windowWidth, windowWidth);
    
    //movie.draw(0, 0);
    //videoCam.draw(0, 0);
    
    switch (currentFilter) {
        case 0:
            colorImgs[0].drawROI(0, 0);
            break;
        case 1:
            colorImgs[1].drawROI(0, 0);
            colorImgs[2].drawROI(0, ofGetHeight() / 2);
            break;
        default:
            colorImgs[1].drawROI(0, 0);
            break;
    }
    
}

void Delaunays::setFilterId(int filterId){
    currentFilter = filterId;
}

void Delaunays::setLowVal(float val){
    lowVal = val;
}

void Delaunays::setFlowResetVal(float val){
    flowResetVal = val;
}