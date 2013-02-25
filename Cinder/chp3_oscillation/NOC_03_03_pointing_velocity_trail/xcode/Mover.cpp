//
//  Mover.cpp
//  NOC_03_03_pointing_velocity_trail
//
//  Created by Matthew Epler on 2/24/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Mover::Mover ()
{
    mLocation = Vec2f( getWindowWidth() / 2, getWindowHeight() / 2);
    mVelocity = Vec2f( 0.0f, 0.0f );
    mTopSpeed = 4.0f;
    mXoff     = 1000.0f;
    mYoff     = 0.0f;
}

void Mover::update( Vec2f mousePos )
{
    Vec2f mouse = mousePos;
    Vec2f mDirection = mouse - mLocation;
    
    mDirection.normalize();
    mDirection *= 0.5f;
    mAcceleration = mDirection;
    
    mVelocity += mAcceleration;
    mVelocity.limit( mTopSpeed );
    mLocation += mVelocity;
}

void Mover::display()
{
    gl::color( 0.5f, 0.5f, 0.5f );
    Rectf rectangle = Rectf( 0, 0, 30, 10 );
    
    // center the rectangle, equal rectMode(CENTER) in Processing
    rectangle.offsetCenterTo( Vec2f( 0, 0 ) );
    
    // Quaternions are used for rotations relative to a point, similar to "heading2D()" in Processing
    ci::Quatf theta( 0, 0, ci::math<float>::atan2( mVelocity.y, mVelocity.x ) );

    gl::pushMatrices();
    gl::translate( mLocation.x, mLocation.y );
        
    gl::rotate( theta );
    gl::drawSolidRect( rectangle );
    
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    gl::drawStrokedRect( rectangle );
    
    gl::popMatrices();
}

void Mover::checkEdges()
{
    if( mLocation.x > getWindowWidth() )
    {
        mLocation.x = 0;
    }
    else if ( mLocation.x < 0 )
    {
        mLocation.x = getWindowWidth();
    }
    
    if ( mLocation.y > getWindowHeight() )
    {
        mLocation.y = 0;
    }
         else if ( mLocation.y < 0 )
    {
        mLocation.y = getWindowHeight();
    }
}
