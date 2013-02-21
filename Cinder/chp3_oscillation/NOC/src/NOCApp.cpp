#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
};

void NOC::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
}

void NOC::update()
{
}

void NOC::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
}


CINDER_APP_BASIC( NOC, RendererGl )
