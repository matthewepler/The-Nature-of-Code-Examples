//
//  Random Walker
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

class RandomWalkLevyApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *walker;
};


void RandomWalkLevyApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 640, 480 );
}

void RandomWalkLevyApp::setup()
{
	// Create a walker object
	walker = new Walker();
}

void RandomWalkLevyApp::update()
{
	walker->step();
}

void RandomWalkLevyApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
	walker->render();
}

CINDER_APP_BASIC( RandomWalkLevyApp, RendererGl )
