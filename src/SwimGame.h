#ifndef SWIM_GAME_H
#define SWIM_GAME_H

#include <SDL.h>
#include <SDL_image.h>
#include <SwimSystem.h>
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

#define SCREEN_WIDTH 920
#define SCREEN_HEIGHT 480
#define FPS 60
#define FRAME_DELAY 1000 / FPS

class SwimGame {
private:
  bool running = false;
  SDL_Window *window;
  std::vector<SwimSystem *> systems;

  void loadSystems();

public:
  static SDL_Renderer *renderer;

  bool isRunning();

  bool init(char *name);
  void update();
  void render();
  void quit();
};

#endif
