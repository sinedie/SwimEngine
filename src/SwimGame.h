#ifndef SWIM_GAME_H
#define SWIM_GAME_H

#include "SwimComponent.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SwimSystem.h>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#define SCREEN_WIDTH 920
#define SCREEN_HEIGHT 480
#define FPS 60
#define FRAME_DELAY 1000 / FPS

class SwimGame {
private:
  bool running = false;
  SDL_Window *window;
  std::vector<SwimSystem *> systems;
  std::vector<SwimEntity *> entities;
  std::vector<BaseComponent *> components;
  std::vector<SwimComponent *> swimComponents;

  void loadSystems();
  void loadComponents();

public:
  static SDL_Renderer *renderer;

  bool isRunning();

  bool init(char *name);
  void update();
  void render();
  void quit();
};

#endif
