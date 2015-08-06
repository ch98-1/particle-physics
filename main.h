/*
3D particle physics simulator
Copyright(C) 2015  Corwin Hansen

This program is free software : you can redistribute it and / or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MAIN_H//include protection
	#define MAIN_H

#include <stdio.h>//input and output
#include <stdlib.h>//standard stuff
#include <math.h>//all the math functions
#include <string.h>//string related things
#include <time.h>//time on system
#include "SDL.h"//include sdl

#define WINDOW_NAME "Particle Rendering"
#define WINDOWFLAGS SDL_WINDOW_OPENGL// window type
#define G 1.0 //gravitational constant

typedef struct positions{//positions for each particles
	double x;
	double y;
	double z;
}positions;

typedef struct velocity{//velocity for each particle
	double x;
	double y;
	double z;
}velocity;

typedef struct force{//force for each particle
	double x;
	double y;
	double z;
}force;

typedef struct color{//color for each particle
	char r;
	char g;
	char b;
	char a;
}color;

typedef struct particle{//position and velocity of each particle
	positions p;
	velocity v;
}particle;

typedef double mass;//mass for each particle

mass *particle_mass;//array of particle mass

particle *particle_data[2];//array of 2 particle data

color *particle_color;//array of particle color

unsigned long long int num_particles;//number of particles in the simulation

unsigned long long int p_time;//current time in simulation

int simulation_thread;//number of thread to run for simulation

int simulation_finished;//number of thread finished for simulation

typedef struct loc{//starting and ending loctaion
	unsigned long long int start;
	unsigned long long int end;
}loc;

SDL_Window *window;//sdl window
SDL_Renderer *renderer;//sdl renderer

int EventFilter(void* userdata, SDL_Event* e);//event filter
void Quit(void);//quit everything
void Usage(const char *arg);//print out usage
int simulate(void *location);//simulate from starting and ending position in the array

#endif
