//
//  ParticleSystem.h
//  NOC_4_09_AdditiveBlending
//
//  Created by Matthew Epler on 3/3/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include "Particle.h"

class ParticleSystem
{
public:
    ParticleSystem( int num, ci::Vec2f v, ci::gl::Texture img );
    ParticleSystem();
    
    std::vector<Particle> mParticles;
    ci::Vec2f             mOrigin;
    ci::gl::Texture       mTexture;
    
    void run();
    void addParticle();
    void addParticle( Particle p );
    bool dead();
};