#ifndef SWIM_SYSTEM_H
#define SWIM_SYSTEM_H

#include <BaseSwimSystem.h>
#include <SDL.h>

class SwimSystem {
private:
  void *dll;
  BaseSwimSystem *system;

public:
  SwimSystem(char *path) {
    dll = SDL_LoadObject(path);
    if (!dll) {
      return;
    }

    BaseSwimSystem *(*createSystem)() =
        (BaseSwimSystem * (*)()) SDL_LoadFunction(dll, "createSystem");

    if (!createSystem) {
      return;
    }

    system = createSystem();
  }

  void test() { system->init(); }

  ~SwimSystem() {
    SDL_UnloadObject(dll);
    system = NULL;
    dll = NULL;
  }
};

#endif
