#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#define SCREEN_WIDTH 920
#define SCREEN_HEIGHT 480
#define FPS 60
#define FRAME_DELAY 1000 / FPS

class Game {
private:
  bool running = false;
  SDL_Window *window;

public:
  static SDL_Renderer *renderer;

  bool isRunning();

  bool init(char* name);
  void update();
  void render();
  void quit();
};

#endif
