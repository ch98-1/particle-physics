#include "all.h"



//set game to starting point
//movement is pixel per second
void init()
{
	minf = 16;
	G = 0.0001;//gravitational constant is 1 for mass of 1 unit here
	strcpy(wtitle, "Particle Phisics(physics)");
	fps = 60;
}