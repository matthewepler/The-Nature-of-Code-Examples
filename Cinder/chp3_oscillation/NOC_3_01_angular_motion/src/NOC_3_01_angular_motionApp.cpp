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
    
    float angle = 0;
    float aVelocity = 0;
    float aAcceleration = 0.0001;
};

void NOC_3_01_angular_motionApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_01_angular_motionApp::setup()
{
}

void NOC_3_01_angular_motionApp::update()
{
}

void NOC_3_01_angular_motionApp::draw()
{
	// clear out the window with white
	gl::clear( Color( 1, 1, 1 ) );
    
    // translate to the middle of the window
    // unlike Processing, push/popping the Matrix necessary when using OpenGL
    gl::pushMatrices();
    gl::translate( getWindowWidth()/2, getWindowHeight()/2 );
    
    // by default, OpenGL is in degrees
    // to convert to radians, use cinder's built-in toDegrees function
    gl::rotate( toDegrees( angle ) );
    
    // draw the line
    gl::color( 0, 0, 0 );
    glLineWidth( 2.0 );
    gl::drawLine( Vec2f( -60.0f, 0.0f), Vec2f( 60.0f, 0.0f ) );
    
    // draw the ellipses with radius of 8 (in Processing it takes diameter, so divide by 2)
    gl::color( 0.5, 0.5, 0.5 );
    gl::drawSolidEllipse( Vec2f(  60.0f, 0.0f ), 8.0f, 8.0f );
    gl::drawSolidEllipse( Vec2f( -60.0f, 0.0f ), 8.0f, 8.0f );
    
    
    // in Cinder, stokes around shapes are drawn seperately
    gl::color( 0, 0, 0 );
    gl::drawStrokedEllipse( Vec2f(  60.0f, 0.0f ), 8.0f, 8.0f );
    gl::drawStrokedEllipse( Vec2f( -60.0f, 0.0f ), 8.0f, 8.0f );
    
    gl::popMatrices();

    // increase angle velocity and acceleration
    angle += aVelocity;
    aVelocity += aAcceleration;
    
}


CINDER_APP_BASIC( NOC_3_01_angular_motionApp, RendererGl )
