//
//  NOC_3_02_forces_angular_mot_trails
//
//  Created by Matthew Epler on 2/18/13.
//
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include <vector>
#include "cinder/Vector.h"
#include "Mover.h"
#include "Attractor.h"

#define ARRAYSIZE 20

//#define

using namespace ci;
using namespace ci::app;
using namespace std;


class NOC_3_02_forces_angular_mot_trailsApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    vector<Mover> mMovers;
    Attractor::Attractor a;
};

void NOC_3_02_forces_angular_mot_trailsApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800.0f, 200.0f );
}

void NOC_3_02_forces_angular_mot_trailsApp::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    
    for( int i = 0; i < 20; i++ )
    {
        mMovers[i] = Mover( 0.9f, 200.0f, 50.0f );
    }
    
    a = Attractor();
}

void NOC_3_02_forces_angular_mot_trailsApp::update()
{
    for( int i = 0; i < 20; i++ ){
		Vec2f force = a.attract( mMovers[i] );
        mMovers[i].applyForce( force );
	}

}

void NOC_3_02_forces_angular_mot_trailsApp::draw()
{
	a.display();
    for( int i = 0; i < 20; i++ ){
		mMovers[i].update();
        mMovers[i].display();
	}
    
}


CINDER_APP_BASIC( NOC_3_02_forces_angular_mot_trailsApp, RendererGl )