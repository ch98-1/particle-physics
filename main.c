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
	if (!( argc == 4 || argc == 8)){//if argument is not the right number
		Usage(argv[0]);//print usage
	}
	else if (strcmp(argv[1], "simulate") == 0 && argc == 4){//simulate from starting positions in the file
		//quit SDL at exit
		atexit(SDL_Quit);

		if (SDL_Init(0) != 0){//start SDL and get any error if it dosen't.
			printf("Could not load SDL: %s\n", SDL_GetError());//print out error
			exit(EXIT_FAILURE);//exit
		}
		//filter events
		SDL_SetEventFilter(EventFilter, NULL);


	}
	else if (strcmp(argv[1], "render") == 0 && argc == 8){//render simulation file
		renderer = NULL;//set values to null
		window = NULL;
		unsigned int width, height;//window width and height
		
		//quit SDL at exit
		atexit(Quit);

		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0){//start SDL and get any error if it dosen't.
			printf("Could not load SDL: %s\n", SDL_GetError());//print out error
			exit(EXIT_FAILURE);//exit
		}

		//filter events
		SDL_SetEventFilter(EventFilter, NULL);

		//Create window
		window = SDL_CreateWindow(
			WINDOW_NAME,                  // window title
			SDL_WINDOWPOS_CENTERED,           // initial x position
			SDL_WINDOWPOS_CENTERED,           // initial y position
			width,                               // width, in pixels
			height,                               // height, in pixels
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
		while (0) {

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
	SDL_DestroyRenderer(renderer);//destroy renderer
	SDL_DestroyWindow(window);//destroy window
	SDL_Quit();//quit SDL
	return;
}

void Usage(const char *arg){//print out usage
	printf("Incorrect arguments\nUsage:\n%s simulate {file} {steps}: Generate simulation file from starting positions in the file.\n%s render {file}  {camera position: x,y,z} {camera pan in degrees: x,y,z} {window size: width,height} {skip} {delay(ms)}: render every {skip} steps in simulation file at path.\nStarting position should be in a text file with particle color r, g, b, a, x position, y position, z position, x speed, y speed, z speed, and  mass in each line as a comma seperated list\n", arg, arg);
}

int simulate(void *location){//simulate from starting and ending position in the array
	loc position = *(loc*)location;//get starting and ending position
	particle *pd_fill = particle_data[p_time % 2];//get particle data to fill
	particle *pd_last = particle_data[p_time + 1 % 2];//get last particle data
	unsigned long long int i;
	for (i = position.start; i <= position.end; i++){//for each particlke in array
		register particle fill = pd_last[i];//get last particle data
		register force particle_force = { 0 };//force of particle
		register mass p_mass = particle_mass[i];//get particle mass
		unsigned long long int j;
		for (j = 0; j < num_particles; j++){//for each particle
			register double rx = fill.p.x - pd_last[j].p.x;//get distances
			register double ry = fill.p.y - pd_last[j].p.y;
			register double rz = fill.p.z - pd_last[j].p.z;
			if (!rx || !ry || !rz) continue;//skip if any was 0
			register double distance = sqrt(rx*rx + ry*ry + rz*rz);//get distance
			register double distance_3 = distance * distance * distance;//get distance cubed
			particle_force.x += ((G*p_mass*particle_mass[j])/distance_3)*rx;//calculate forces
			particle_force.y += ((G*p_mass*particle_mass[j]) / distance_3)*ry;
			particle_force.z += ((G*p_mass*particle_mass[j]) / distance_3)*rz;
		}
		fill.v.x += particle_force.x / p_mass;//get velocity
		fill.v.y += particle_force.y / p_mass;
		fill.v.z += particle_force.z / p_mass;
		fill.p.x += fill.v.x;//get position
		fill.p.y += fill.v.y;
		fill.p.z += fill.v.z;
		pd_fill[i] = fill;//set data
	}
}