//
//  Mover.h
//  NOC_2_7_attraction_many
//
//  Created by Greg Kepler on 11/13/12.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Mover {
public:
	Mover( float m, float x , float y );
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
	
	void applyForce( ci::Vec2f force );
	void update();
	void checkEdges();
	void display();
	void reset( ci::Vec2f loc );
};