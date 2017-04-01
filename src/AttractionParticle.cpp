#include "AttractionParticle.h"

AttractionParticle::AttractionParticle(){
    radius = 0.1;
    friction = 0.02;
    mass = 1.0;
    bFixed = false;
}

void AttractionParticle::setup(ofVec3f _position, ofVec3f _velocity){
    // 位置を設定
    position = _position;
    // 初期速度を設定
    velocity = _velocity;
}
void AttractionParticle::setup(float positionX, float positionY, float positionZ, float velocityX, float velocityY, float velocityZ){
    // 位置を設定
    position = ofVec3f(positionX, positionY, positionZ);
    // 初期速度を設定
    velocity = ofVec3f(velocityX, velocityY, velocityZ);
}

// 力をリセット
void AttractionParticle::resetForce(){
    force.set(0, 0, 0);
}

// 力を加える
void AttractionParticle::addForce(ofVec3f _force){
    force += _force / mass;
}
void AttractionParticle::addForce(float forceX, float forceY, float forceZ){
    force += ofVec3f(forceX, forceY, forceZ);
}

// 摩擦力の更新
void AttractionParticle::updateForce(){
    force -= velocity * friction;
}

// 位置の更新
void AttractionParticle::updatePos(){
    if (!bFixed) {
        velocity += force;
        position += velocity;
    }
}

// 力の更新と座標の更新をupdateとしてまとめる
void AttractionParticle::update(){
    updateForce();
    updatePos();
}


// 画面の端でバウンドする(改定版)
void AttractionParticle::bounceOffWalls(){
    bool bDampedOnCollision = false;
    bool bDidICollide = false;
    
    //float minx = 0;
    //float miny = 0;
    //float minz = 0;
    //float maxx = 2000;
    //float maxy = 2000;
    //float maxz = 2000;
    float minx = -800;
    float miny = -800;
    float minz = -800;
    float maxx = 800;
    float maxy = 800;
    float maxz = 800;
    
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
        bDidICollide = true;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
        bDidICollide = true;
    }
    
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
        bDidICollide = true;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
        bDidICollide = true;
    }
    
    if (position.z > maxz){
        position.z = maxz;
        velocity.z *= -1;
        bDidICollide = true;
    } else if (position.z < minz){
        position.z = minz;
        velocity.z *= -1;
        bDidICollide = true;
    }
    
    if (bDidICollide == true && bDampedOnCollision == true){
        velocity *= 0.3;
    }
}

void AttractionParticle::throughOfWalls(){
    //float minx = 0;
    //float miny = 0;
    //float minz = 0;
    //float maxx = 2000;
    //float maxy = 2000;
    //float maxz = 2000;
    float minx = -800;
    float miny = -800;
    float minz = -800;
    float maxx = 800;
    float maxy = 800;
    float maxz = 800;
    
    
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.z < minz) {
        position.z = maxz;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
    if (position.z > maxz) {
        position.z = minz;
    }
    
}

// 描画
void AttractionParticle::draw(){
    ofCircle(position, 1.0);
}

// 反発する力
void AttractionParticle::addRepulsionForce(float x, float y, float z, float radius, float scale){
    // 力の中心点を設定
    ofVec3f posOfForce;
    posOfForce.set(x,y,z);
    // パーティクルと力の中心点との距離を計算
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうか判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら、計算しない
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    // 設定した半径の内側だったら
    if (bAmCloseEnough == true){
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x + diff.x * scale * pct;
        force.y = force.y + diff.y * scale * pct;
        force.z = force.z + diff.z * scale * pct;
    }
}

// 引き付けあう力
void AttractionParticle::addAttractionForce(float x, float y, float z, float radius, float scale){
    // 力の中心点を設定
    ofVec3f posOfForce;
    posOfForce.set(x,y,z);
    // パーティクルと力の中心点との距離を計算
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    // 力が働く範囲かどうか判定する変数
    bool bAmCloseEnough = true;
    // もし設定した半径より外側だったら、計算しない
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    // 設定した半径の内側だったら
    if (bAmCloseEnough == true){
        // 距離から点にかかる力ベクトルを計算
        float pct = 1 - (length / radius);
        diff.normalize();
        force.x = force.x - diff.x * scale * pct;
        force.y = force.y - diff.y * scale * pct;
        force.z = force.z - diff.z * scale * pct;
    }
}