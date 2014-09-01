#ifndef _ALL_H_
    #define _ALL_H_

#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//particle array
struct particles{
	double mass;
	double xpos;
	double ypos;
	double xvol;
	double yvol;
	double xacc;
	double yacc;
};



//time of last frame and last FPS last FPS shown
unsigned int lft;
unsigned int lfps;
unsigned int lfpss;

//min millisecond per flame
int minf;

//window title
char wtitle[50];

//frame per second
float fps;

//init function
void init();

//constants
double G;


#endif
