//
//  MonteCarlo
//  The Nature of Code
//
//  Converted from Daniel Shiffman's Processing Examples
//  Created by Greg Kepler
//

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class MonteCarloApp : public AppBasic {
  public:
	void prepareSettings( Settings *settings );
	void setup();
	void update();
	void draw();
	float montecarlo();
	
	vector<float> vals;
	vector<float> norms;
	int width, height;
};

void MonteCarloApp::prepareSettings( Settings *settings )
{
	settings->setWindowSize( 200, 200 );
}

void MonteCarloApp::setup()
{
	width = getWindowWidth();
	height = getWindowHeight();
	vals.resize(width);
	norms.resize(width);
}

void MonteCarloApp::update()
{
}


// An algorithm for picking a random number based on monte carlo method
// Here probability is determined by formula y = x
float MonteCarloApp::montecarlo() {
	// Have we found one yet
	bool foundone = false;
	int hack = 0;  // let's count just so we don't get stuck in an infinite loop by accident
	while (!foundone && hack < 10000) {
		// Pick two random numbers
		float r1 = randFloat(1);
		float r2 = randFloat(1);
		float y = r1*r1;  // y = x*x (change for different results)
		// If r2 is valid, we'll use this one
		if (r2 < y) {
			foundone = true;
			return r1;
		}
		hack++;
	}
	// Hack in case we run into a problem (need to improve this)
	return 0;
}

void MonteCarloApp::draw()
{
	gl::clear( Color( 0.39f, 0.39f, 0.39f ) );
	
	// Pick a random number between 0 and 1 based on custom probability function
	float n = montecarlo();
	
	// What spot in the array did we pick
	int index = int(n*width);
	vals[index]++;
	//stroke(255);
	gl::color(1, 1, 1);
	
	bool normalization = false;
	float maxy = 0.0;
	
	// Draw graph based on values in norms array
	// If a value is greater than the height, set normalization to true
	for (int x = 0; x < vals.size(); x++) {
		gl::drawLine(Vec2f(x, height), Vec2f(x, height - norms[x]));
		if (vals[x] > height) normalization = true;
		if (vals[x] > maxy) maxy = vals[x];
	}
	
	// If normalization is true then normalize to height
	// Otherwise, just copy the info
	for (int x = 0; x < vals.size(); x++) {
		if (normalization) norms[x] = (vals[x] / maxy) * (height);
		else norms[x] = vals[x];
	}
}

CINDER_APP_BASIC( MonteCarloApp, RendererGl )
