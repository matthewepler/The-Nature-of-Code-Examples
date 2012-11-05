#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Perlin.h"
#include "cinder/gl/Texture.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Exc_I_9_Noise3DApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	
	float increment = 0.01f;
	float zoff = 0.0;			// The noise function's 3rd argument, a global variable that increments once per cycle
	float zincrement = 0.02;	// We will increment zoff differently than xoff and yoff
	
	Perlin mPerlin;
};

void Exc_I_9_Noise3DApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize(200, 200);
}

void Exc_I_9_Noise3DApp::setup()
{
	mPerlin = Perlin();
}

void Exc_I_9_Noise3DApp::update()
{
}

void Exc_I_9_Noise3DApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
	
	// create a surface object to apply the pixel values to
	Surface pixelSurface(200, 200, true);
	float xoff = 0.0; // Start xoff at 0
	
	// For every x,y coordinate in a 2D space, calculate a noise value and produce a brightness value
	for(int x = 0; x < getWindowWidth(); x++){
		xoff += increment;
		float yoff = 0.0;
		for(int y=0; y<getWindowHeight(); y++){
			yoff += increment;
			
			// Calculate noise and scale by 255
			float bright = (mPerlin.fBm(xoff, yoff, zoff)+0.5) * 255;
			
			// Try using this line instead
//			int bright = randInt(0,255);
			
			// Set each pixel onscreen to a grayscale value
			pixelSurface.setPixel(Vec2i(x, y), Color8u(bright, bright, bright));
		}
	}
	
	gl::draw(gl::Texture( pixelSurface ));
	zoff += zincrement; // Increment zoff
}

CINDER_APP_BASIC( Exc_I_9_Noise3DApp, RendererGl )
