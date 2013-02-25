#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_05_simple_harmonic_mot_trailApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
};

void NOC_3_05_simple_harmonic_mot_trailApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_05_simple_harmonic_mot_trailApp::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    gl::enableAlphaBlending();
}

void NOC_3_05_simple_harmonic_mot_trailApp::update()
{
}

void NOC_3_05_simple_harmonic_mot_trailApp::draw()
{
    float alphaVal = lmap<float>( 5, 0, 255, 0, 1 );
    gl::color( 1, 1, 1, alphaVal );
    Rectf background = Rectf( Vec2f( 0, 0 ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawSolidRect( background );
    
    float period = 120;
    float amplitude = 300;
    
    // Calculating horizontal location according to formula for simple harmonic motion
    float x = amplitude * cos( ( 2 * M_PI * getElapsedFrames() ) / period );
    
    gl::pushMatrices();
    gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );

    gl::color( 0.5f, 0.5f, 0.5f );
    gl::drawLine( Vec2f( 0, 0 ), Vec2f( x, 0 ) );
    gl::drawSolidEllipse( Vec2f( x, 0 ), 24, 24 );
    
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    gl::drawStrokedEllipse( Vec2f( x, 0 ), 24, 24 );
    
    gl::popMatrices();
}


CINDER_APP_BASIC( NOC_3_05_simple_harmonic_mot_trailApp, RendererGl )
