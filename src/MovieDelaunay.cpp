#include "MovieDelaunay.h"

Delaunays::Delaunays(){
    flow.resetFlow();
    //movie.load("movies/fingers.mov");
    //movie.load("movies/dancing.mp4");
    //movie.setLoopState(OF_LOOP_NORMAL);
    //movie.play();
    
    count = 0;
}

Delaunays::~Delaunays(){
}

void Delaunays::init(){
    cout << "START" << endl;
    movie.load("movies/dancing.mp4");
    movie.setLoopState(OF_LOOP_NORMAL);
    //movie.play();
}


void Delaunays::update(){
    //flow.resetFeaturesToTrack();
    movie.play();
    movie.update();
    flow.calcOpticalFlow(movie.getPixelsRef());

    
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
    
    movie.update();

    if((count % 20) == 0){
        flow.resetFeaturesToTrack();
    }
    
    count++;
    
    int triangleNum = delaunay.getNumTriangles();
    for(int i = 0; i < triangleNum; i++){
        if(i % 15 == 0){
            ITRIANGLE index = delaunay.getTriangleAtIndex(i);
            vector<ofPoint> trianglePoints = delaunay.getPointsForITriangle(index);
        
            for(int j = 0; j < trianglePoints.size(); j++){
                triangleMesh.addVertex(trianglePoints[j]);
                triangleMesh.addColor(ofColor(255));
            }
        }
    }
    
    
}

void Delaunays::draw(){
    
    ofSetColor(255);
    //movie.draw(0,0);
    ofNoFill();
    delaunay.draw();
    ofFill();
    triangleMesh.draw();
    
    
    movie.draw(0, 0);

}