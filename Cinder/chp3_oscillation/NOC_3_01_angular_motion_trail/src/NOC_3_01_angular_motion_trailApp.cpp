#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_01_angular_motion_trailApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    float angle = 0;
    float aVelocity = 0;
    float aAcceleration = 0.0001;
};

void NOC_3_01_angular_motion_trailApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_01_angular_motion_trailApp::setup()
{
    // clear out the window with white
	gl::clear( Color( 1, 1, 1 ) );
    
    // turn on alpha blending
    gl::enableAlphaBlending();
}

void NOC_3_01_angular_motion_trailApp::update()
{
}

void NOC_3_01_angular_motion_trailApp::draw()
{    
    // draw the alpha background every frame for gradient trail effect
    // all color/alpha values are between 0 and 1, so map the value if translating from Processing
    float alphaValue = lmap<float>( 5, 0, 255, 0, 1 );
    gl::color( 1, 1, 1, alphaValue );
    Rectf backgroundAlpha = Rectf( Vec2f( 0.0f, 0.0f ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawSolidRect( backgroundAlpha );
    
    // another way to do this is to get the Area of the window and use that to create a Rect object
    // Area bounds = getWindowBounds();
    // Rectf backgroundAlpha = Rectf( bounds );
    // gl::drawSolidRect( backgroundAlpha );
    
    gl::color( 0.5f, 0.5f, 0.5f );
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


CINDER_APP_BASIC( NOC_3_01_angular_motion_trailApp, RendererGl )
