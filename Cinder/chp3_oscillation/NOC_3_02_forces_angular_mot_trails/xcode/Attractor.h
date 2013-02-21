//
//  Attractor.h
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/20/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/Vector.h"
#include "Mover.h"
#include <vector>

class Attractor {
public:
	Attractor();

    float       mMass;
    float       g;
    ci::Vec2f   mLocation;
    
    ci::Vec2f   attract( Mover m );
    void        display();
    
};
