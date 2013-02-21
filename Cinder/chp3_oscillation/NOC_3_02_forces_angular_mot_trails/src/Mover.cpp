//
//  Mover.cpp
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/18/13.
//
//
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "cinder/Vector.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Mover::Mover( float m, float x , float y )
{
    mMass         = m;
	mLocation     = Vec2f( x, y );
	mVelocity     = Vec2f( randFloat( 0.0f ), randFloat( 0.0f ) );
	mAcceleration = Vec2f( 0.0f, 0.0f );
    
    mAngle             = 0.0f;
    mAngleVelocity     = 0.0f;
    mAngleAcceleration = 0.0f;
}

void Mover::applyForce( ci::Vec2f force )
{
    Vec2f f = force / mMass;
    mAcceleration += f;
}

void Mover::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    
    mAngleAcceleration = mAcceleration.x / 10.0f;
    mAngleVelocity += mAngleAcceleration;
    mAngleVelocity = constrain( mAngleVelocity, -0.1f, 0.1f );
    mAngle += mAngleVelocity;
    
    mAcceleration *= 0.0f;
}

void Mover::display()
{
    float alphaValue = lmap<float> ( 200, 0, 255, 0, 1 );
    gl::color( 0.5f, 0.5f, 0.5f, alphaValue );
    
    gl::pushMatrices();
    gl::translate( mLocation.x, mLocation.y );
    
    // by default, OpenGL is in degrees
    // to convert to radians, use cinder's built-in toDegrees function
    gl::rotate( toDegrees( mAngle ) );
    
    Rectf rectangle = Rectf();
    rectangle.scaleCentered( mMass * 16 );
    gl::drawSolidRect( rectangle );
    
    gl::popMatrices();
}