#include <Game.h>

SDL_Renderer *Game::renderer = nullptr;

bool Game::isRunning() { return running; }

bool Game::init(char *name) {
  std::cout << "Initializing... " << std::flush;

  /* Initializes the timer, audio, video, joystick,
  haptic, gamecontroller and events subsystems */
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cout << "Error initializing SDL: " << SDL_GetError() << std::endl;
    return false;
  }

  /* Create a window */
  window =
      SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                       SCREEN_WIDTH, SCREEN_HEIGHT, 0);

  if (!window) {
    std::cout << "Error creating window: " << SDL_GetError() << std::endl;
    return false;
  }

  /* Create a renderer */
  Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
  renderer = SDL_CreateRenderer(window, -1, render_flags);

  if (!renderer) {
    std::cout << "Error creating renderer: " << SDL_GetError() << std::endl;
    return false;
  }

  /* Initialize PNG loading */
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    std::cout << "SDL_image could not initialize! SDL_image Error: "
              << IMG_GetError() << std::endl;
    return false;
  }

  running = true;
  std::cout << "Done" << std::endl;
  return running;
}

void Game::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    }
  }
}

void Game::render() {
  /* Clear screen */
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  /* Draw to window and loop */
  SDL_RenderPresent(renderer);
}

void Game::quit() {
  /* Release resources */
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = NULL;
  }

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}
