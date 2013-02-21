//
//  Mover.h
//  NOC
//
//  Created by Matthew Epler on 2/20/13.
//
//

#ifndef __NOC__Mover__
#define __NOC__Mover__

#include <iostream>

#endif /* defined(__NOC__Mover__) */

//
//  Mover.h
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/18/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include <vector>

class Mover {
public:
	Mover( float m, float x , float y );
	
	ci::Vec2f	mLocation, mVelocity, mAcceleration;
	float		mMass;
    float       mAngle;
    float       mAngleVelocity;
    float       mAngleAcceleration;
    
	void		applyForce( ci::Vec2f force );
	void		update();
	void		display();
};