/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz_ref.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 10:30:14 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/04 17:56:19 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main() 
{ 
	// SDL_SetRenderDrawColor();
	// SDL_RenderPresent()
	// retutns zero on success else non-zero 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
		printf("Error initializing SDL: %s\n", SDL_GetError()); 
	} 
	SDL_Window* win = SDL_CreateWindow("Lem-in Visualizer", // creates a window 
									SDL_WINDOWPOS_CENTERED, 
									SDL_WINDOWPOS_CENTERED, 
									WIDTH, HEIGHT, 0); 

	// triggers the program that controls 
	// your graphics hardware and sets flags 
	Uint32 render_flags = SDL_RENDERER_ACCELERATED; 

	// creates a renderer to render our images 
	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags); 
	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	// creates a surface to load an image into the main memory 
	SDL_Surface* start;
	SDL_Surface* end;
	SDL_Surface* surface; 

	// please provide a path for your image 
	start = IMG_Load("./sq_start.jpg");
	// end = IMG_Load("./sq_end.jpg");
	end = IMG_Load("./boi.gif");
	surface = IMG_Load("./sq.jpg"); 

	// loads image to our graphics hardware memory. 
	SDL_Texture* s_tex = SDL_CreateTextureFromSurface(rend, start); 
	SDL_Texture* e_tex = SDL_CreateTextureFromSurface(rend, end); 
	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 

	// clears main-memory 
	SDL_FreeSurface(start); 
	SDL_FreeSurface(end); 
	SDL_FreeSurface(surface); 

	// let us control our image position 
	// so that we can move it with our keyboard. 
	SDL_Rect start_box;
	SDL_Rect end_box;
	SDL_Rect dest; 

	// connects our texture with dest to control position 
	SDL_QueryTexture(s_tex, NULL, NULL, &start_box.w, &start_box.h); 
	SDL_QueryTexture(e_tex, NULL, NULL, &end_box.w, &end_box.h); 
	SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 

	// adjust height and width of our image box. 
	dest.w /= 6; 
	dest.h /= 6; 

	end_box.w *= 10; 
	end_box.h *= 10; 

	// sets initial x-position of object 
	dest.x = (WIDTH - dest.w) / 2; 
	start_box.x = 950;
	end_box.x = 450;

	// sets initial y-position of object 
	dest.y = (HEIGHT - dest.h) / 2; 
	start_box.y = 150;
	end_box.y = 250;

	SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	// thickLineColor(rend, (start_box.x + (start_box.w /2)), (start_box.y + (start_box.h /2)), (end_box.x + (end_box.w /2)), (end_box.y + (end_box.h /2)), 8, 0xFFFFFF00);
	// SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
	// draws line from middle of start square to middle of moveable square
	// SDL_RenderDrawLine(rend, start_box.x, start_box.y, dest.x, dest.y);

	// SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
	// controls annimation loop 
	int close = 0; 

	// speed of box 
	int speed = 300; 

	// annimation loop 
	while (!close) { 
		SDL_Event event; 

		// Events mangement 
		while (SDL_PollEvent(&event)) { 
			switch (event.type) { 

			case SDL_QUIT: 
				// handling of close button 
				close = 1; 
				break; 

			case SDL_KEYDOWN: 
				// keyboard API for key pressed 
				switch (event.key.keysym.scancode) { 
				case SDL_SCANCODE_W: 
				case SDL_SCANCODE_UP: 
					dest.y -= speed / 50; 
					break; 
				case SDL_SCANCODE_A: 
				case SDL_SCANCODE_LEFT: 
					dest.x -= speed / 50; 
					break; 
				case SDL_SCANCODE_S: 
				case SDL_SCANCODE_DOWN: 
					dest.y += speed / 50; 
					break; 
				case SDL_SCANCODE_D: 
				case SDL_SCANCODE_RIGHT: 
					dest.x += speed / 50; 
					break; 
				case SDL_SCANCODE_Q:
					close = 1;
					break; 
				} 
			} 
		} 

		// right boundary 
		if (dest.x + dest.w > WIDTH) 
			dest.x = WIDTH - dest.w; 

		// left boundary 
		if (dest.x < 0) 
			dest.x = 0; 

		// bottom boundary 
		if (dest.y + dest.h > HEIGHT) 
			dest.y = HEIGHT - dest.h; 

		// upper boundary 
		if (dest.y < 0) 
			dest.y = 0; 

		// clears the screen 
		SDL_RenderClear(rend); 
		// stringRGBA(rend, start_box.x, start_box.y - 50, "START", 0, 0, 0, 255);
		stringColor(rend, start_box.x, start_box.y - 20, "START", 0xFFFFFF00);
		thickLineColor(rend, (start_box.x + (start_box.w /2)), (start_box.y + (start_box.h /2)), (end_box.x + (end_box.w /2)), (end_box.y + (end_box.h /2)), 8, 0xFFFFFF00);
		SDL_RenderCopy(rend, s_tex, NULL, &start_box);
		SDL_RenderCopy(rend, e_tex, NULL, &end_box);
		SDL_RenderCopy(rend, tex, NULL, &dest); 



		// SDL_SetRenderDrawColor(rend, 0, 255, 255, 255);
		// draws line from middle of start square to middle of moveable square
		// SDL_RenderDrawLine(rend, (start_box.x + (start_box.w /2)), (start_box.y + (start_box.h /2)), (dest.x + (dest.w /2)), (dest.y + (dest.h /2)));
		thickLineColor(rend, (start_box.x + (start_box.w /2)), (start_box.y + (start_box.h /2)), (dest.x + (dest.w /2)), (dest.y + (dest.h /2)), 8, 0xFFFFFF00);

		SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
		// triggers the double buffers 
		// for multiple rendering 
		SDL_RenderPresent(rend); 

		// calculates to 60 fps 
		SDL_Delay(1000 / 120); 
	} 

	// destroy texture 
	SDL_DestroyTexture(tex); 
	SDL_DestroyTexture(s_tex); 
	SDL_DestroyTexture(e_tex); 

	// destroy renderer 
	SDL_DestroyRenderer(rend); 

	// destroy window 
	SDL_DestroyWindow(win); 
	return 0; 
} 
