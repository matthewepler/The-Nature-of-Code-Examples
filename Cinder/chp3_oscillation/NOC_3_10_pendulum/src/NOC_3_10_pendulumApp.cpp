#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_10_pendulumApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void NOC_3_10_pendulumApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_10_pendulumApp::setup()
{
}

void NOC_3_10_pendulumApp::mouseDown( MouseEvent event )
{
}

void NOC_3_10_pendulumApp::update()
{
}

void NOC_3_10_pendulumApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}


CINDER_APP_BASIC( NOC_3_10_pendulumApp, RendererGl )
