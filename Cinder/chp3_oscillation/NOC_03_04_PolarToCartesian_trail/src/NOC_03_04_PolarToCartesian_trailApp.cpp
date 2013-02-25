#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_03_04_PolarToCartesian_trailApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    float r, theta;
};

void NOC_03_04_PolarToCartesian_trailApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_03_04_PolarToCartesian_trailApp::setup()
{
    gl::enableAlphaBlending();
    gl::clear( Color( 1, 1, 1 ) );
    
    r = getWindowHeight() * 0.45;
    theta = 0.0f;
}


void NOC_03_04_PolarToCartesian_trailApp::update()
{
}

void NOC_03_04_PolarToCartesian_trailApp::draw()
{
	float alphaVal = lmap<float>( 5, 0, 255, 0, 1 );
    gl::color( 1, 1, 1, alphaVal );
    Rectf background = Rectf( Vec2f( 0, 0 ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawSolidRect( background );
    
    gl::pushMatrices();
    gl::translate( getWindowWidth() / 2, getWindowHeight() / 2 );
    
    float x = r * cos( theta );
    float y = r * sin( theta );
    
    gl::color( 0.5, 0.5, 0.5 );
    gl::drawSolidEllipse( Vec2f( x, y ), 24, 24 );
    
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    gl::drawLine( Vec2f( 0, 0 ), Vec2f( x, y ) );
    gl::drawStrokedEllipse( Vec2f( x, y ), 24, 24 );

    gl::popMatrices();
    
    theta += 0.02;
}


CINDER_APP_BASIC( NOC_03_04_PolarToCartesian_trailApp, RendererGl )
