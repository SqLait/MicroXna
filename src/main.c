#include <SDL2/SDL.h>
#include "../MicroXnaLib/Window/window.h"

XnaWindow window;
int quit = 0;

void GameLoop() {
  SDL_Event e;

  // Initialize the window and renderer before the game loop starts
  InitWindow(&window, 860, 680);

  while (!quit) {
    // Handle events on the queue
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = 1;
      }
    }

    // Clear screen
    SDL_SetRenderDrawColor(window.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(window.renderer);

    // Render red filled quad
    SDL_Rect fillRect = {860 / 4, 680 / 4, 860 / 2, 680 / 2};
    SDL_SetRenderDrawColor(window.renderer, 0xFF, 0x00, 0x00, 0xFF);        
    SDL_RenderFillRect(window.renderer, &fillRect);

    // Update screen
    SDL_RenderPresent(window.renderer);
  }
}

int main(int argc, char* args[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Run the game loop
  GameLoop();

  // Clean up and quit SDL
  DestroyWindow(&window);
  SDL_Quit();

  return 0;
}

