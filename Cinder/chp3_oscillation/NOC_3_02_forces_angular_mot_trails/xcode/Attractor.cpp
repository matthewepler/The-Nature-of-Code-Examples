//
//  Example 3_02: Forces with (arbitrary) angular motion
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Matthew Epler
//

#include "Attractor.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Attractor::Attractor()
{
    mLocation = Vec2f( 800 / 2, 200 / 2 );
    mMass = 20.0f;
    mGravity = 0.4f;
}


Vec2f Attractor::attract( const Mover &m )
{
    Vec2f force = mLocation - m.mLocation;
    
    float distance = force.length();
    distance = constrain<float>( distance, 5.0f, 25.0f );
    
    force.normalize();
    
    float strength = (mGravity * mMass * m.mMass) / ( distance * distance );
    force *= strength;
    
    return force;
}

void Attractor::display()
{
    gl::color( 0.5f, 0.5f, 0.5f );
    gl::drawSolidEllipse( mLocation, 24, 24 );
    gl::color( 0, 0, 0 );
    glLineWidth( 2.0 );
    gl::drawStrokedEllipse( mLocation, 24, 24);
}