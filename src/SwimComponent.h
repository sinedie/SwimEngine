#ifndef SWIM_COMPONENT_H
#define SWIM_COMPONENT_H

#include <BaseSwimSystem.h>
#include <SDL2/SDL.h>

typedef BaseComponent *(*ComponentCreator)();

class SwimComponent {
private:
  void *dll;
  ComponentCreator caller;

public:
  SwimComponent(const char *path) {
    dll = SDL_LoadObject(path);
    if (!dll) {
      return;
    }

    caller = (ComponentCreator)SDL_LoadFunction(dll, "createComponent");
  }

  BaseComponent *create() { return caller(); }

  ~SwimComponent() {
    SDL_UnloadObject(dll);
    dll = NULL;
  }
};

#endif
