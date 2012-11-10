//
//  Noise Walk Velocity
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NoiseWalkVelocityApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *w;
};

void NoiseWalkVelocityApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 400 );
	settings->setFrameRate( 30.0 );
}

void NoiseWalkVelocityApp::setup()
{
	w = new Walker();
}

void NoiseWalkVelocityApp::update()
{
	w->walk();
}

void NoiseWalkVelocityApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	w->display();
}

CINDER_APP_BASIC( NoiseWalkVelocityApp, RendererGl )
