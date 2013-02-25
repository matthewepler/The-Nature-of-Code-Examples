//
//  Attractor.h
//  NOCWTF
//
//  Created by Matthew Epler on 2/20/13.
//
//
#pragma once

#include "cinder/app/AppBasic.h"
#include "Mover.h"

class Attractor {
public:
    
    Attractor();
    
    ci::Vec2f   mLocation;
    float       mMass, mGravity;
    
    ci::Vec2f attract( const Mover &m );
    void display();
};