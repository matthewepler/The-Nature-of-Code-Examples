#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_01_exercise_batonApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    float angle = 0;
};

void NOC_3_01_exercise_batonApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 750, 150 );
}

void NOC_3_01_exercise_batonApp::setup()
{
}

void NOC_3_01_exercise_batonApp::update()
{
}

void NOC_3_01_exercise_batonApp::draw()
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
    gl::drawLine( Vec2f( -50.0f, 0.0f), Vec2f( 50.0f, 0.0f ) );
	
    
    // draw the ellipses with radius of 8 (in Processing it takes diameter, so divide by 2)
    gl::color( 0.5, 0.5, 0.5 );
    gl::drawSolidEllipse( Vec2f(  50.0f, 0.0f ), 8.0f, 8.0f );
    gl::drawSolidEllipse( Vec2f( -50.0f, 0.0f ), 8.0f, 8.0f );
    
    
    // in Cinder, stokes around shapes are drawn seperately
    gl::color( 0, 0, 0 );
    gl::drawStrokedEllipse( Vec2f(  50.0f, 0.0f ), 8.0f, 8.0f );
    gl::drawStrokedEllipse( Vec2f( -50.0f, 0.0f ), 8.0f, 8.0f );

    gl::popMatrices();
    
    // increase angle of rotation every loop
    angle += 0.05;
}


CINDER_APP_BASIC( NOC_3_01_exercise_batonApp, RendererGl )
