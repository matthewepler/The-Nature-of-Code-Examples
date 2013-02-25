//
//  Pendulum.cpp
//  NOC_3_10_pendulum
//
//  Created by Matthew Epler on 2/24/13.
//
//

#include "cinder/app/AppBasic.h"
#include "Pendulum.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Pendulum::Pendulum( Vec2f origin, float radius )
{
    mOrigin = origin;
    mLocation = Vec2f();
    mRadius = radius / 2; // Processing uses diameter, Cinder uses radii.
    mAngle = M_PI / 4;
    mAngVel = 0.0f;
    mAngAcc = 0.0f;
    mDamping = 0.995;
    mBallRadius = 48.0;
}

void Pendulum::go()
{
    update();
    drag();
    display();
}

void Pendulum::update()
{
    if( !dragging )
    {
        float gravity = 0.4f;
        
        mAngAcc  = (-1 * gravity / mRadius ) * sin( mAngle );
        mAngVel += mAngAcc;
        mAngVel *= mDamping;
        mAngle  += mAngVel;
    }
}

void Pendulum::display()
{
    mLocation.set( Vec2f( mRadius * sin( mAngle ), mRadius * cos( mAngle ) ) );
    mLocation += mOrigin;
    
    if( dragging )
    {
        gl::color( 0, 0, 0 );
    }
    else
    {
    gl::color( 0.5, 0.5, 0.5 );
    }
    
    gl::drawSolidEllipse( mLocation, mRadius, mRadius );
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    gl::drawLine( mOrigin, mLocation );
    gl::drawStrokedEllipse( mLocation, mRadius, mRadius );
}

void clicked( Vec2f mousePos )
{
    // couldn't find an equivalent to Processing's dist() function
    Vec2f mouse = mousePos;
    if( mouse.x < mLocation.x + mRadius && mouse.x > mLocation.x - mRadius && mouse.y < mLocation.y + mRadius && mouse.y > mLocation.y - mRadius )
    {
        dragging = true;
    }
}