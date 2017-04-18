#include "MovieDelaunay.h"

Delaunays::Delaunays(){
    movie.load("movies/fingers.mov");
    movie.setLoopState(OF_LOOP_NORMAL);
    movie.play();
}

Delaunays::~Delaunays(){
}

void Delaunays::update(){
    movie.update();
}

void Delaunays::draw(){
    movie.draw(0, 0);
}