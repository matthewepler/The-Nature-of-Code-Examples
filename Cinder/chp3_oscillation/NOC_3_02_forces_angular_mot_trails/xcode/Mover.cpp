//
//  Mover.cpp
//  NOCWTF
//
//  Created by Matthew Epler on 2/20/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Mover::Mover( float m, float x, float y )
{
    mMass           = m;
    mLocation       = Vec2f( x, y );
    mVelocity       = Vec2f( randFloat( -1.0f, 1.0f ), randFloat( -1.0f, 1.0f ) );
    mAcceleration   = Vec2f( 0, 0 );
    
    mAngle  = 0;
    mAngVel = 0;
    mAngAcc = 0;
}

void Mover::applyForce( Vec2f force )
{
    Vec2f f = force / mMass;
    mAcceleration += f;
}

void Mover::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    
    mAngAcc = mAcceleration.x / 10.0;
    mAngVel += mAngAcc;
    mAngVel = constrain( mAngVel, -0.1f, 0.1f );
    mAngle += mAngVel;
    
    mAcceleration *= 0;
}

void Mover::display()
{
    float alphaVal = lmap<float>( 200, 0, 255, 0, 1 );
    gl::color( 0.5f, 0.5f, 0.5f, alphaVal );
    
    Rectf rectangle = Rectf( Vec2f( 0, 0 ), Vec2f( mMass * 16, mMass * 16 ) );
    rectangle.offsetCenterTo( Vec2f( 0, 0 ) );
    gl::pushMatrices();
    
    gl::translate( mLocation.x, mLocation.y );
    gl::rotate( toDegrees( mAngle ) );
    gl::drawSolidRect( rectangle );
    
    gl::color( 0, 0, 0, alphaVal );
    glLineWidth(2.0);
    gl::drawStrokedRect( rectangle );
    
    gl::popMatrices();
    
}