//
//  Pendulum.cpp
//  NOC_3_10_PendulumExample
//
//  Created by Greg Kepler on 1/19/13.
//
//

#include "Pendulum.h"

Pendulum::Pendulum()
{
	
}

// This constructor could be improved to allow a greater variety of pendulums
Pendulum::Pendulum( ci::Vec2f origin, float r )
{
	// Fill all variables
	mOrigin = origin;
    mLocation = Vec2f(0, 0);
    mR = r;
    mAngle = M_PI/4;
	
    mAVelocity = 0.0;
    mAAcceleration = 0.0;
    mDamping = 0.995;   // Arbitrary damping
    mBallr = 48.0;      // Arbitrary ball radius
}


void go() {
    update();
    drag();    //for user interaction
    display();
}

// Function to update location
void update() {
    // As long as we aren't dragging the pendulum, let it swing!
    if (!dragging) {
		float gravity = 0.4;                              // Arbitrary constant
		aAcceleration = (-1 * gravity / r) * sin(angle);  // Calculate acceleration (see: http://www.myphysicslab.com/pendulum1.html)
		aVelocity += aAcceleration;                 // Increment velocity
		aVelocity *= damping;                       // Arbitrary damping
		angle += aVelocity;                         // Increment angle
    }
}

void display() {
    location.set(r*sin(angle), r*cos(angle), 0);         // Polar to cartesian conversion
    location.add(origin);                              // Make sure the location is relative to the pendulum's origin
	
    stroke(0);
    strokeWeight(2);
    // Draw the arm
    line(origin.x, origin.y, location.x, location.y);
    ellipseMode(CENTER);
    fill(175);
    if (dragging) fill(0);
    // Draw the ball
    ellipse(location.x, location.y, ballr, ballr);
}


// The methods below are for mouse interaction

// This checks to see if we clicked on the pendulum ball
void clicked(int mx, int my) {
    float d = dist(mx, my, location.x, location.y);
    if (d < ballr) {
		dragging = true;
    }
}

// This tells us we are not longer clicking on the ball
void stopDragging() {
    aVelocity = 0; // No velocity once you let go
    dragging = false;
}

void drag() {
    // If we are draging the ball, we calculate the angle between the
    // pendulum origin and mouse location
    // we assign that angle to the pendulum
    if (dragging) {
		PVector diff = PVector.sub(origin, new PVector(mouseX, mouseY));      // Difference between 2 points
		angle = atan2(-1*diff.y, diff.x) - radians(90);                      // Angle relative to vertical axis
    }
}