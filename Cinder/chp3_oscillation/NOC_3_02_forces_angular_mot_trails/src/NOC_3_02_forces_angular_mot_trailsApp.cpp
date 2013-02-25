#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Mover.h"
#include "Attractor.h"

using namespace ci;
using namespace ci::app;
using namespace std;

#define ARRAYSIZE 20

// Greg, I kept getting an error with the getWindowWidth() and getWindowHeight() funcitons. Something about threading...?
#define WIDTH 800
#define HEIGHT 200


class NOCWTFApp : public AppBasic {
public:
    void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
    
    vector<Mover>	mMovers;
    Attractor       mAttractor;
};

void NOCWTFApp::prepareSettings( Settings *settings )
{
    settings->setWindowSize( WIDTH, HEIGHT );
}

void NOCWTFApp::setup()
{
    // Clear the window and enable alpha blending for "trail" effect
    gl::clear( Color( 1, 1, 1 ) );
    gl::enableAlphaBlending();
    
    // Initialize the vector (similar to an ArrayList in Processing)
    mMovers = vector<Mover>();
    
    // Create one Mover at a time and add it to the vector.
    for( int i = 0; i < ARRAYSIZE; i++ )
    {
        mMovers.push_back( Mover( randFloat( 0.1f, 2.0f ), randFloat( WIDTH ), randFloat( HEIGHT ) ) );
    }
    
    // Initialize Attractor object
    mAttractor = Attractor();
}

void NOCWTFApp::update()
{
    // Udpate the position and orientation of the Movers based on the Attractor's force
    for( int i = 0; i < ARRAYSIZE; i++ )
    {
        Vec2f force = mAttractor.attract( mMovers[i] );
        mMovers[i].applyForce( force );
        mMovers[i].update();
    }
}

void NOCWTFApp::draw()
{
    gl::clear( Color( 1, 1, 1 ) );
    
    // to add "trail" effect, comment the gl::clear above, then:
    // Map the alpha value from Processing (0-255) to Cinder (0-1), then draw background and all objects
    
//    float alphaVal = lmap<float>( 5, 0, 255, 0, 1 );
//    gl::color( 1, 1, 1, alphaVal );
//    Rectf background = Rectf( Vec2f( 0.0f, 0.0f ), Vec2f( getWindowWidth(), getWindowHeight() ) );
//    gl::drawSolidRect( background );

    mAttractor.display();
    
    for( int i = 0; i < ARRAYSIZE; i++ )
    {
        mMovers[i].display();
    }
}


CINDER_APP_BASIC( NOCWTFApp, RendererGl )
