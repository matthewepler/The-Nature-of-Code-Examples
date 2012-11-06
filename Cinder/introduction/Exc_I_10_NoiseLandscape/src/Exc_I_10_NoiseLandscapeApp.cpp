#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"
#include "Landscape.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exc_I_10_NoiseLandscapeApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings);
	void setup();
	void update();
	void draw();
	
	Landscape	*land;
	float		theta;
};

void Exc_I_10_NoiseLandscapeApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize(800, 200);
	land = new Landscape(20, 800, 400);
	land->calculate();
}

void Exc_I_10_NoiseLandscapeApp::setup()
{
	theta = 0.0f;
}

void Exc_I_10_NoiseLandscapeApp::update()
{
}

void Exc_I_10_NoiseLandscapeApp::draw()
{
	gl::clear( Color( 1, 1, 1 ) );
	//gl::enableWireframe();
	
	glPushMatrix();
	gl::translate((float)getWindowWidth()/2,(float)getWindowHeight()/2+20,-160);

	float xRot = toDegrees(M_PI/3);
	float zRot = toDegrees(theta);
	gl::rotate(Vec3f(xRot, 0, zRot));
	land->render();
	glPopMatrix();
	
	land->calculate();
	
	theta += 0.0025;
}

CINDER_APP_BASIC( Exc_I_10_NoiseLandscapeApp, RendererGl )
