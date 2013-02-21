//
//  Mover.cpp
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/18/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"


using namespace ci;
using namespace ci::app;
using namespace std;

Mover::Mover( float m, float x , float y ):
{
    mMass         = m;
	mLocation     = Vec2f( x, y );
	mVelocity     = Vec2f( randFloat( -1, 1 ), randFloat( -1, 1 ) );
	mAcceleration = Vec2f( 0.0, 0.0 );
}