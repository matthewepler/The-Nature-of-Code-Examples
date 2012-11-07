//
//  Random Walk Trail
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//
//


#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Walker.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomWalkTrailApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *walker;
};


void RandomWalkTrailApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 400, 400 );
	settings->setFrameRate( 30.0f );
}

void RandomWalkTrailApp::setup()
{
	walker = new Walker();
}

void RandomWalkTrailApp::update()
{
	walker->walk();
}

void RandomWalkTrailApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	walker->display();
}

CINDER_APP_BASIC( RandomWalkTrailApp, RendererGl )