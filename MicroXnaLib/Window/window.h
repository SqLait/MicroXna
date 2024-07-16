#define WINDOW_H
#ifdef WINDOW_H
#include <SDL2/SDL.h>

typedef union {
  SDL_Window* window;
  SDL_Renderer* renderer;
} XnaWindow;

void InitWindow(XnaWindow*, int, int);
void DestroyWindow(XnaWindow*);
#endif
