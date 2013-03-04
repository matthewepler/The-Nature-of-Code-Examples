//
//  Particle.cpp
//  NOC_4_09_AdditiveBlending
//
//  Created by Matthew Epler on 3/3/13.
//
//

#include "Particle.h"
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"


using namespace ci;
using namespace ci::app;
using namespace std;

extern ci::gl::Texture img;

Particle::Particle( Vec2f location, ci::gl::Texture img )
{
    mAcceleration = Vec2f( 0.0f, 0.05f );
    mVelocity     = Vec2f( randFloat( -1.0f, 1.0f ), randFloat( -1.0f, 1.0f ) );
    mVelocity     *= 2.0f;
    mLocation.set( location );
    mTexture      = img;
}


void Particle::run()
{
    update();
    render();
}

void Particle::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    lifespan -= 2.0f;
}

void Particle::render()
{
    gl::draw( mTexture, mLocation );
}

bool Particle::isDead()
{
    if( lifespan <= 0.0 )
    {
        return true;
    } else {
        return false;
    }
}