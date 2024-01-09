#include <ControlsSystem.h>

void ControlsSystem::init() {
  std::cout << "Init controls system" << std::endl;
};

void ControlsSystem::update() {
  for (auto &e : entities) {
    Motion *motion =
        reinterpret_cast<Motion *>(e->getComponent(typeid(Motion)));

    const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);

    if (currentKeyStates[SDL_SCANCODE_LEFT] ||
        currentKeyStates[SDL_SCANCODE_A]) {
      motion->velocity.x = -motion->speed.x;
    } else if (currentKeyStates[SDL_SCANCODE_RIGHT] ||
               currentKeyStates[SDL_SCANCODE_D]) {
      motion->velocity.x = motion->speed.x;
    } else {
      motion->velocity.x = 0;
    }

    if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_W]) {
      motion->velocity.y = motion->speed.y;
    } else if (currentKeyStates[SDL_SCANCODE_DOWN] ||
               currentKeyStates[SDL_SCANCODE_S]) {
      motion->velocity.y = -motion->speed.y;
    } else {
      motion->velocity.y = 0;
    }
  }
};
