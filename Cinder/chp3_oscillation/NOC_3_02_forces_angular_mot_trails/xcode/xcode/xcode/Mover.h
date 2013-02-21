//
//  Mover.h
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/18/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Mover {
public:
	Mover( float m, float x , float y );
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
	float       angle;
    float       aVelocity;
    float       aAcceleration;
    
	void		applyForce( ci::Vec2f force );
	void		update();
	void		display();
};