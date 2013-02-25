#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_3_08_static_wave_linesApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    float angle, angleVel;
};

void NOC_3_08_static_wave_linesApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_3_08_static_wave_linesApp::setup()
{
    angle = 0;
    angleVel = 0.2;
    
    gl::clear( Color( 1, 1, 1 ) );
}

void NOC_3_08_static_wave_linesApp::mouseDown( MouseEvent event )
{
    gl::clear( Color( 1, 1, 1 ) );
    
    gl::color( 0, 0, 0 );
    glLineWidth( 2 );
    
    gl::begin(GL_LINE_STRIP);
    for( int x = 0; x < getWindowWidth(); x += 5 )
    {
        float y = lmap<float>( sin( angle ), -1, 1, 0, getWindowHeight() );
        gl::vertex( x, y );
        angle += angleVel;
    }
    gl::end();
}

void NOC_3_08_static_wave_linesApp::update()
{
}

void NOC_3_08_static_wave_linesApp::draw()
{

    
}


CINDER_APP_BASIC( NOC_3_08_static_wave_linesApp, RendererGl )
