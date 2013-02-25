//
//  Oscillator.cpp
//  NOC_03_07_oscillating_objects_trail
//
//  Created by Matthew Epler on 2/24/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "Oscillator.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Oscillator::Oscillator()
{
    mAngle = Vec2f();
    mVelocity = Vec2f( randFloat( -0.05f, 0.05f ), randFloat( -0.05f, 0.05f ) );
    mAmplitude = Vec2f( randFloat( 20, getWindowWidth() / 2 ), randFloat( 20, getWindowHeight() / 2 ) );
}

void Oscillator::oscillate()
{
    mAngle += mVelocity;
}

void Oscillator::display()
{
    float x = sin( mAngle.x ) * mAmplitude.x;
    float y = cos( mAngle.y ) * mAmplitude.y;
    
    gl::pushMatrices();
    gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
    
    gl::color( 0.5, 0.5, 0.5, 0.5 );
    gl::drawSolidEllipse( Vec2f( x, y ),  16, 16 );
    
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    gl::drawLine( Vec2f( 0, 0 ), Vec2f( x, y ) ) ;
    gl::drawStrokedEllipse( Vec2f( x, y ), 16, 16 );
    
    gl::popMatrices();
}