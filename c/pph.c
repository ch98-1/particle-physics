#include "pph.h"

int main()
{

	//initialise everything
	init();
	int L = gline("particles.txt");
		//no function is used to make stuff simpler
		SDL_Init(SDL_INIT_EVERYTHING);
		
		SDL_Window *window;                    // Declare a pointer

		window = SDL_CreateWindow(
			wtitle,                  // window title
			SDL_WINDOWPOS_UNDEFINED,           // initial x position
			SDL_WINDOWPOS_UNDEFINED,           // initial y position
			640,                               // width, in pixels
			480,                               // height, in pixels
			SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
			// flags 
			);
		if (window == NULL) {
			// If window could not be made...
			printf("Could not create window: %s\n", SDL_GetError());
			return 1;
		}

		//set last frame time and last FPS time to now
		lft = SDL_GetTicks();
		lfps = SDL_GetTicks();
		lfpss = SDL_GetTicks();

		struct particles particlelist[500];
		//load particlelist
		gparticles("particles.txt", particlelist);

		//create renderer
		SDL_Renderer* screen = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		//Event handler
		SDL_Event ev;





		//set draw color
		SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);


		int x = 0;
		int y = 0;

		//main loop
		while (quit == 0)
		{
			//event handling
			//Handle events on queue
			while (SDL_PollEvent(&ev) != 0)
			{

				switch (ev.type)
				{

					//User requests quit
				case SDL_QUIT:
					quit = 1;
					break;

					//User presses a key
				case SDL_KEYDOWN:
					switch (ev.key.keysym.sym)
					{
					case SDLK_UP: //jump up
						//if keypress is up
						break;

					case SDLK_DOWN:
						//if keypress is down
						break;

					case SDLK_LEFT:
						//if keypress is left
						break;

					default:

						break;
					}

					break;
				default:
					break;
				}
			}


			//window with and window hight
			int* ww;
			int* wh;

			//get window size
			SDL_GetWindowSize(window, &ww, &wh);
			SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);

			
			//gravity and some other thing
			x = 0;
			while (x < L){
				particlelist[x].xacc = 0;
				particlelist[x].yacc = 0;
				y = 0;
				while (y < L){



					
					// not so scientific gravity code 1
					double grav = particlelist[x].mass*particlelist[y].mass*G;//grav = mass*mass2*G
					if (particlelist[x].xpos - particlelist[y].xpos < 0){
						particlelist[x].xacc = particlelist[x].xacc + (grav / (particlelist[x].xpos - particlelist[y].xpos)*(particlelist[x].xpos - particlelist[y].xpos)) / particlelist[x].mass;//acceleration + (grav/distance*distance)/mass
					}
					else if (particlelist[x].xpos - particlelist[y].xpos > 0){
						particlelist[x].xacc = particlelist[x].xacc - (grav / (particlelist[x].xpos - particlelist[y].xpos)*(particlelist[x].xpos - particlelist[y].xpos)) / particlelist[x].mass;
					}
					if (particlelist[x].ypos - particlelist[y].ypos < 0){
						particlelist[x].yacc = particlelist[x].yacc + (grav / (particlelist[x].ypos - particlelist[y].ypos)*(particlelist[x].ypos - particlelist[y].ypos)) / particlelist[x].mass;//acceleration + (grav/distance*distance)/mass
					}
					else if (particlelist[x].ypos - particlelist[y].ypos > 0){
						particlelist[x].yacc = particlelist[x].yacc - (grav / (particlelist[x].ypos - particlelist[y].ypos)*(particlelist[x].ypos - particlelist[y].ypos)) / particlelist[x].mass;
					}  


					/*
					//test movement code 
					particlelist[x].xacc = particlelist[x].xacc + 0.001;
					particlelist[x].xacc = particlelist[x].xacc + 0.001;
					*/

					y++;
				}
				particlelist[x].xvol = particlelist[x].xvol + particlelist[x].xacc;
				particlelist[x].yvol = particlelist[x].yvol + particlelist[x].yacc;
				x++;
			}
			x = 0;
			while (x  < L){
				particlelist[x].xpos = particlelist[x].xpos + particlelist[x].xvol;
				particlelist[x].ypos = particlelist[x].ypos + particlelist[x].yvol;
				x++;
			}


			SDL_SetRenderDrawColor(screen, 255, 255, 255, 255);
			//clear
			SDL_RenderClear(screen);



			//draw
			SDL_SetRenderDrawColor(screen, 0, 0, 0, 255);
			x = 0;
			while (x  < L){
				SDL_RenderDrawPoint(screen, particlelist[x].xpos, particlelist[x].ypos);
				
				x++;
			}



			//update
			SDL_RenderPresent(screen);


			if (minf > (SDL_GetTicks() - lft)) {
				SDL_Delay(minf - (SDL_GetTicks() - lft));  // Pause execution for 16 milliseconds from last  frame
			}
			lft = SDL_GetTicks();
			fps = (float)1000 / (SDL_GetTicks() - lfps);
			lfps = SDL_GetTicks();
			if (1000 < (SDL_GetTicks() - lfpss)){
				strcpy(wtitle, "Origami Knight ");
				char sfps[10];
				sprintf(sfps, "%.1f", fps);
				strcat(wtitle, sfps);
				strcat(wtitle, "fps");
				SDL_SetWindowTitle(window, wtitle);
				lfpss = SDL_GetTicks();
			}
		}

		// clear screen
		SDL_RenderClear(screen);
		//Destroy Renderer
		SDL_DestroyRenderer(screen);
		// Close and destroy the window
		SDL_DestroyWindow(window);

		// Clean up
		SDL_Quit();

}
