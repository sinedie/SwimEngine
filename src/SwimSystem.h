#ifndef SWIM_SYSTEM_H
#define SWIM_SYSTEM_H

#include <BaseSwimSystem.h>
#include <SDL2/SDL.h>

typedef BaseSwimSystem *(*SystemCreator)();

class SwimSystem {
private:
  void *dll;
  BaseSwimSystem *system;

public:
  SwimSystem(const char *path) {
    dll = SDL_LoadObject(path);
    if (!dll) {
      return;
    }

    SystemCreator createSystem =
        (SystemCreator)SDL_LoadFunction(dll, "createSystem");

    if (!createSystem) {
      return;
    }

    system = createSystem();
  }

  void update(BaseComponent *component) { system->update(component); }

  ~SwimSystem() {
    SDL_UnloadObject(dll);
    system = NULL;
    dll = NULL;
  }
};

#endif
