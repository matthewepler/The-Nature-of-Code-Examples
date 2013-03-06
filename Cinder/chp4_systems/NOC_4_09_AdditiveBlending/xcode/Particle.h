//
//  Particle.h
//  NOC_4_09_AdditiveBlending
//
//  Created by Matthew Epler on 3/3/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"

class Particle
{
public:
    Particle( ci::Vec2f location, ci::gl::Texture image );
    
    ci::Vec2f       mLocation;
    ci::Vec2f       mVelocity;
    ci::Vec2f       mAcceleration;
    ci::gl::Texture particleTexture;
    float           lifespan;
    
    void run();
    void update();
    void render();
    bool isDead();
};