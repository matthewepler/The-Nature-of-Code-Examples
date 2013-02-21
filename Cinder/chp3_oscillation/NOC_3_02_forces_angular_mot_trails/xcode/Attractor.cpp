//
//  Attractor.cpp
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/20/13.
//
//

#include "Attractor.h"

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include <vector>
#include "cinder/Vector.h"

using namespace ci;
using namespace ci::app;
using namespace std;


Attractor::Attractor()
{
    mLocation = Vec2f( 400.0f, 100.0f );
    mMass     = 20.0f;
    g         = 0.4f;
}


Vec2f Attractor::attract( Mover m )
{
    Vec2f force = mLocation - m.mLocation;
    float distance = force.length();
    distance = constrain( distance, 5.0f, 25.0f );
    force.normalize();
    float strength = ( g * mMass * m.mMass ) / ( distance * distance );
    force *= strength;
    return force;
}

void Attractor::display()
{
    gl::color( 0.5f, 0.5f, 0.5f );
    gl::drawSolidEllipse( mLocation, 48.0f, 48.0f );
    
    glLineWidth(2);
    gl::color( 0, 0, 0 );
    gl::drawStrokedEllipse( mLocation, 48.0f, 48.0f );
}