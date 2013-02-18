#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_01_angular_motionApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
    void setup();
	void update();
	void draw();
};

void NOC_3_01_angular_motionApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 750, 150 );
    //glEnable(GL_LINE_SMOOTH);
}

void NOC_3_01_angular_motionApp::setup()
{
}


void NOC_3_01_angular_motionApp::update()
{
}

void NOC_3_01_angular_motionApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}


CINDER_APP_BASIC( NOC_3_01_angular_motionApp, RendererGl )
