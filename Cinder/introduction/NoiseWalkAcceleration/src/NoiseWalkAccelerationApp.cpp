//
//  Noise Walk Acceleration
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

class NoiseWalkAccelerationApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *w;
};

void NoiseWalkAccelerationApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
}

void NoiseWalkAccelerationApp::setup()
{
	w = new Walker();
}

void NoiseWalkAccelerationApp::update()
{
	w->walk();
}

void NoiseWalkAccelerationApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	
	w->display();
}

CINDER_APP_BASIC( NoiseWalkAccelerationApp, RendererGl )
