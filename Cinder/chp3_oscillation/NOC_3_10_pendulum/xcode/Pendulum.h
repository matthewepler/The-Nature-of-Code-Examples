//
//  Pendulum.h
//  NOC_3_10_pendulum
//
//  Created by Matthew Epler on 2/24/13.
//
//

#pragma once

#include "cinder/app/AppBasic.h"

class Pendulum {
public:
    Pendulum( ci::Vec2f origin, float radius );
    
    ci::Vec2f   mLocation;
    ci::Vec2f   mOrigin;
    float       mRadius;
    float       mAngle;
    float       mAngVel;
    float       mAngAcc;
    float       mBallRadius;
    float       mDamping;
    bool        dragging;
    
    void go();
    void update();
    void display();
    void clicked( ci::Vec2f mousePos );
    void stopDragging();
    void drag();
};
