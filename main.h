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
#define WINDOWFLAGS SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE //resizable window
#define WIDTH 600 //width and height of window
#define HEIGHT 400

SDL_Window *window;//sdl window
SDL_Renderer *renderer;//sdl renderer

int EventFilter(void* userdata, SDL_Event* e);//event filter
void Quit(void);//quit everything
void Usage(const char *arg);//print out usage

#endif
