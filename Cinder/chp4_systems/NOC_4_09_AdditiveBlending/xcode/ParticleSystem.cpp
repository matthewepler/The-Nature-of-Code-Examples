//
//  ParticleSystem.cpp
//  NOC_4_09_AdditiveBlending
//
//  Created by Matthew Epler on 3/3/13.
//
//

#include "ParticleSystem.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;


ParticleSystem::ParticleSystem( int num, Vec2f v, ci::gl::Texture img )
{
    mParticles = vector<Particle>();
    mOrigin    = *( &v );
    mTexture   = img;
    for( int i = 0; i < num; i++ )
    {
        mParticles.push_back( Particle( mOrigin, mTexture ) );
    }
}

ParticleSystem::ParticleSystem()
{
}

void ParticleSystem::run()
{
    for( vector<Particle>::iterator i = mParticles.end(); i != mParticles.begin(); --i ){
		i->run();
        if( i->isDead() )
        {
            mParticles.erase( i );
        }
	}
}

void ParticleSystem::addParticle()
{
    mParticles.push_back( Particle( mOrigin, mTexture ) );
}

void ParticleSystem::addParticle( Particle p )
{
    mParticles.push_back( p );
}

bool ParticleSystem::dead()
{
    if( mParticles.empty() )
    {
        return true;
    } else {
        return false;
    }
}