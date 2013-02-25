#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

#include "Mover.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class NOC_03_03_pointing_velocity_trailApp : public AppBasic {
  public:
    void prepareSettings( Settings *settings );
	void setup();
    void mouseDrag( MouseEvent event );
	void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
	void update();
	void draw();
    
    Mover *mMover;
    bool mousePressed;
};

void NOC_03_03_pointing_velocity_trailApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( 800, 200 );
}

void NOC_03_03_pointing_velocity_trailApp::setup()
{
    gl::enableAlphaBlending();
    gl::clear( Color( 1, 1, 1 ) );
    mMover = new Mover();
}

void NOC_03_03_pointing_velocity_trailApp::mouseDrag( MouseEvent event )
{
    if( mousePressed == true )
    {
        mMover -> display();
    }
}

// there might be a more elegant way to do this, but this shows how to split 3 diff mouse events and get them working together.
void NOC_03_03_pointing_velocity_trailApp::mouseDown( MouseEvent event )
{
    mousePressed = true;
}

void NOC_03_03_pointing_velocity_trailApp::mouseUp( MouseEvent event )
{
    mousePressed = false;
}

void NOC_03_03_pointing_velocity_trailApp::update()
{
    mMover -> update( getMousePos() );
    mMover -> checkEdges();
}

void NOC_03_03_pointing_velocity_trailApp::draw()
{    
    float alphaVal = lmap<float>( 5, 0, 255, 0, 1 );
    gl::color( 1, 1, 1, alphaVal );
    Rectf background = Rectf( Vec2f( 0, 0 ), Vec2f( getWindowWidth(), getWindowHeight() ) );
    gl::drawSolidRect( background );

}


CINDER_APP_BASIC( NOC_03_03_pointing_velocity_trailApp, RendererGl )
