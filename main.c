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
#include "main.h"//main header


int main(int argc, char *argv[]){
	if (!(argc == 3 || argc == 4 || argc == 5)){//if argument is not the right number
		Usage(argv[0]);//print usage
	}
	else if (strcmp(argv[1], "simulate") == 0){//simulate from starting positions in the file
		if (SDL_Init(0) != 0){//start SDL and get any error if it dosen't.
			printf("Could not load SDL: %s\n", SDL_GetError());//print out error
			exit(EXIT_FAILURE);//exit
		}
	}
	else if (strcmp(argv[1], "render") == 0){//render simulation file
		renderer = NULL;//set values to null
		window = NULL;

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){//start SDL and get any error if it dosen't.
			printf("Could not load SDL: %s\n", SDL_GetError());//print out error
			exit(EXIT_FAILURE);//exit
		}

		//filter events
		SDL_SetEventFilter(EventFilter, NULL);

		//quit SDL at exit
		atexit(Quit);

		//Create window
		window = SDL_CreateWindow(
			WINDOW_NAME,                  // window title
			SDL_WINDOWPOS_CENTERED,           // initial x position
			SDL_WINDOWPOS_CENTERED,           // initial y position
			WIDTH,                               // width, in pixels
			HEIGHT,                               // height, in pixels
			WINDOWFLAGS        //use these flags
			);

		// Check that the window was made
		if (window == NULL) {
			// In the event that the window could not be made...
			printf("Could not create window: %s\n", SDL_GetError());
			exit(EXIT_FAILURE);//exit
		}

		//Create renderer
		renderer = SDL_CreateRenderer(window, -1, 0);

		// Check that the renderer was made
		if (renderer == NULL) {
			// In the event that the window could not be made...
			printf("Could not create renderer: %s\n", SDL_GetError());
			exit(EXIT_FAILURE);//exit
		}

		//initialise and load stuff

		//main loop
		while (1) {

		}
	}
	else{//if argument is not right number
		Usage(argv[0]);//print usage
	}
	exit(EXIT_SUCCESS);//exit
}

int EventFilter(void* userdata, SDL_Event* e){//event filter
	switch (e->type) {//for each event type
	case SDL_QUIT://quit everything
		exit(EXIT_SUCCESS);//exit
		return 0;//delete that event
		break;//get out
	}
	return 1;//just in case something wiard happens
}

void Quit(void){//quit everything

	SDL_Quit();//quit SDL
	
	return;//exit function if it didn't exit for some reason
}

void Usage(const char *arg){//print out usage
	printf("Incorrect arguments\nUsage:\n%s simulate {file} {number of thread to run}: Generate simulation file from starting positions in the file. Use single thread if it was not specified\n%s render {file} {window width} {window height}: render simulation file at path. use default window size if it was not specified\nStarting position should be in a text file with particle name, x position, y position, z position, x speed, y speed, and z speed in each line as a comma seperated list\nYou have to have a text file named configure.txt with the first line listing camera position x, y, z, and camera pan x, y, z, and starting fron next line, particle name, and it's information in each line as a comma seperated list in the running directry to run the simulation", arg, arg);
}