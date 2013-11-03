//
//  particle.cpp
//  leap_ver2
//
//  Created by yoji yamaura on 2013/08/05.
//
//

#include "particle.h"
#include "ofMain.h"


// コンストラクタ
particle::particle(){
    setInitialCondition(0, 0);
    damping = 0.06f;
}

//
void particle::resetForce(){
    frc.set(0,0);
}

//
void particle::addForce(float x, float y){
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//
void particle::addDampingForce(){
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//
/*void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
}*/
void particle::setInitialCondition(float px, float py){
    pos.set(px,py);
	//vel.set(vx,vy);
}


//------------------------------------------------------------
void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}
/*void particle::update(float x, float y){
	//vel = vel + frc;
	pos = pos + vel;
}*/

//------------------------------------------------------------
void particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}