//
//  particle.h
//  leap_ver2
//
//  Created by yoji yamaura on 2013/08/05.
//
//

#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle{
    
public:
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition(float px, float py);
	void update();
	void draw();
	
	float damping;
    
protected:
private:
};

#endif // PARTICLE_H