//
//  Walker.h
//	The Nature of Code
//
//  Created by Greg Kepler
//
//

#import "cinder/Perlin.h"

class Walker
{
public:
	Walker();
	void render();
	void step();
	
private:
	int			mX, mY;
	ci::Perlin	mPerlin;
	bool		mReady;
};
