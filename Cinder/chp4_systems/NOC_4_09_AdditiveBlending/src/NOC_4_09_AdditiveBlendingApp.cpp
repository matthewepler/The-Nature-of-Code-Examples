#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIo.h"

#include "Particle.h"
#include "ParticleSystem.h"

using namespace ci;
using namespace ci::app;
using namespace std;


class NOC_4_09_AdditiveBlendingApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

    ParticleSystem  ps;
    ci::gl::Texture img;
};

void NOC_4_09_AdditiveBlendingApp::prepareSettings( Settings *settings )
{
    setWindowSize( 640, 360 );
}

void NOC_4_09_AdditiveBlendingApp::setup()
{
    img =  loadImage( loadResource( "texture.png" ) );
    ps = ParticleSystem( 25, Vec2f( getWindowWidth(), 50.0f ), img );
    
    gl::enableAdditiveBlending();
}

void NOC_4_09_AdditiveBlendingApp::mouseDown( MouseEvent event )
{
}

void NOC_4_09_AdditiveBlendingApp::update()
{
}

void NOC_4_09_AdditiveBlendingApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    ps.run();
    for( int i = 0; i < 10; i++ )
    {
        ps.addParticle();
    }
}


CINDER_APP_BASIC( NOC_4_09_AdditiveBlendingApp, RendererGl )
