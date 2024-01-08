#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include <SwimGame.h>

int main(int argc, char *args[]) {
  SwimGame game = SwimGame();

  if (!game.init("RogueLike")) {
    std::cout << "Failed to initialize!" << std::endl;
    game.quit();
    return 1;
  }

  Uint32 frameStart;
  int frameTime;

  while (game.isRunning()) {
    frameStart = SDL_GetTicks();

    game.update();
    game.render();

    frameTime = SDL_GetTicks() - frameStart;
    if (FRAME_DELAY > frameTime) {
      SDL_Delay(FRAME_DELAY - frameTime);
    }
  }

  game.quit();
  return 0;
}
