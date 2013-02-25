//
//  Mover.h
//  NOCWTF
//
//  Created by Matthew Epler on 2/20/13.
//
//
#pragma once

#include "cinder/app/AppBasic.h"

class Mover {
public:
    Mover();
    Mover( float m, float x, float y );
    
    ci::Vec2f   mLocation, mVelocity, mAcceleration;
    float       mMass, mAngle, mAngVel, mAngAcc;
    
    void applyForce( ci::Vec2f force );
    void update();
    void display();
};