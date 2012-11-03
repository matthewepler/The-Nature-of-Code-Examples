//
//  Random Walk Noise
//  The Nature of Code
//
//  Converted from Dan Shiffman's Processing Examples
//  Created by Greg Kepler
//
//


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomWalkNoiseApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *walker;
};


void RandomWalkNoiseApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 360 );
	settings->setFrameRate(30.0f);
}

void RandomWalkNoiseApp::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	// Create a walker object
	walker = new Walker();
}

void RandomWalkNoiseApp::update()
{
	walker->step();
}

void RandomWalkNoiseApp::draw()
{
	
	walker->render();
}

CINDER_APP_BASIC( RandomWalkNoiseApp, RendererGl )
