#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_09_waveApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    float startAngle;
    float angleVel;
};

void NOC_3_09_waveApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_09_waveApp::setup()
{
    gl::enableAlphaBlending();
    
    startAngle = 0;
     angleVel  = 0.23;
    // angleVel  = 0.05; // example NOC_3_09_wave_a
    // angleVel  = 0.2; // example NOC_3_09_wave_b
    // angleVel  = 0.4; // example NOC_3_09_wave_c
}

void NOC_3_09_waveApp::update()
{
}

void NOC_3_09_waveApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );

    startAngle += 0.015;
    float angle = startAngle;
    
    for( int x = 0; x < getWindowWidth(); x += 24 )
    {
        float y = lmap<float>( sin( angle ), -1, 1, 0, getWindowHeight() );
        float alphaVal = lmap<float>( 50, 0, 255, 0, 1 );
        gl::color( 0, 0, 0, alphaVal );
        gl::drawSolidEllipse( Vec2f( x, y ), 24, 24 );
        gl::color( 0, 0, 0 );
        glLineWidth( 2 );
        gl::drawStrokedEllipse( Vec2f( x, y ), 24, 24 );
        
        angle += angleVel;
    }
}


CINDER_APP_BASIC( NOC_3_09_waveApp, RendererGl )
