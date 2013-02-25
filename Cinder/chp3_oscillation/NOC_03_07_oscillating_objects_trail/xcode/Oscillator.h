//
//  Oscillator.h
//  NOC_03_07_oscillating_objects_trail
//
//  Created by Matthew Epler on 2/24/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Oscillator
{
public:
    Oscillator();
    
    ci::Vec2f   mAngle;
    ci::Vec2f   mVelocity;
    ci::Vec2f   mAmplitude;
    
    void oscillate();
    void display();
};
