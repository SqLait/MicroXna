#include <SDL2/SDL.h>
#include "window.h" 

void InitWindow(XnaWindow* window, int width, int height) {
  window->window = SDL_CreateWindow("SDL Window",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    width,
                                    height,
                                    SDL_WINDOW_SHOWN);
  window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED);
}

void DestroyWindow(XnaWindow* window) {
  if (window->renderer) {
    SDL_DestroyRenderer(window->renderer);
    window->renderer = NULL;
  }
  if (window->window) {
    SDL_DestroyWindow(window->window);
    window->window = NULL;
  }
}

