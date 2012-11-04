//
//  Random Walk Traditional 2
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

class RandomWalkTraditional2App : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	Walker *walker;
};


void RandomWalkTraditional2App::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void RandomWalkTraditional2App::setup()
{
	gl::clear( Color( 0, 0, 0 ) );
	// Create a walker object
	walker = new Walker();
}

void RandomWalkTraditional2App::update()
{
	walker->step();
}

void RandomWalkTraditional2App::draw()
{
	
	walker->render();
}

CINDER_APP_BASIC( RandomWalkTraditional2App, RendererGl )
