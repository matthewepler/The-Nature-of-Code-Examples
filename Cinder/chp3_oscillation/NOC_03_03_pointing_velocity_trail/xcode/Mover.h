//
//  Mover.h
//  NOC_03_03_pointing_velocity_trail
//
//  Created by Matthew Epler on 2/24/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Mover {
public:
    Mover();
    
    ci::Vec2f   mLocation, mVelocity, mAcceleration;
    float       mTopSpeed;
    float       mXoff, mYoff;
    float       mRadius;
    
    void update( ci::Vec2f mousePos );
    void display();
    void checkEdges();
};
