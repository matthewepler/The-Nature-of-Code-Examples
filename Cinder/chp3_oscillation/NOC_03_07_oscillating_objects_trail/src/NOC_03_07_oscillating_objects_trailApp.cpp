#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Oscillator.h"

#define ARRAYSIZE 10

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_03_07_oscillating_objects_trailApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    vector<Oscillator>	mOscillators;
};

void NOC_03_07_oscillating_objects_trailApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_03_07_oscillating_objects_trailApp::setup()
{
    gl::clear( Color( 1, 1, 1 ) );
    gl::enableAlphaBlending();
    
    mOscillators = vector<Oscillator>();
    
    for( int i = 0; i < ARRAYSIZE; i++ )
    {
        mOscillators.push_back( Oscillator() );
    }
}

void NOC_03_07_oscillating_objects_trailApp::mouseDown( MouseEvent event )
{
}

void NOC_03_07_oscillating_objects_trailApp::update()
{
}

void NOC_03_07_oscillating_objects_trailApp::draw()
{
	float alphaVal = lmap<float>( 5, 0, 255, 0, 1 );
    gl::color( 1, 1, 1, alphaVal );
    Rectf background = Rectf( Vec2f( 0.0f, 0.0f ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawSolidRect( background );
    
    // use an iterator when you don't need to address objects individually for modifications
    for( vector<Oscillator>::iterator i = mOscillators.begin(); i != mOscillators.end(); ++i ){
		i->oscillate();
        i->display();
	}
}


CINDER_APP_BASIC( NOC_03_07_oscillating_objects_trailApp, RendererGl )
