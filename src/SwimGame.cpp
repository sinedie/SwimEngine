#include <SwimGame.h>

SDL_Renderer *SwimGame::renderer = nullptr;

bool SwimGame::isRunning() { return running; }

void SwimGame::loadComponents() {

  std::string path = "./plugins/components/";

  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    std::cout << "Loading " << entry.path() << "... " << std::flush;

    SwimComponent *component = new SwimComponent(entry.path().string().c_str());
    swimComponents[entry.path().filename()] = component;

    std::cout << "DONE " << std::endl;
  }
}

void SwimGame::loadSystems() {

  std::string path = "./plugins/systems/";

  for (const auto &entry : std::filesystem::directory_iterator(path)) {
    std::cout << "Loading " << entry.path() << "... " << std::flush;

    SwimSystem *sys = new SwimSystem(entry.path().string().c_str());
    systems.push_back(sys);

    std::cout << "DONE " << std::endl;
  }
}

bool SwimGame::init(char *name) {
  std::cout << "Initializing... " << std::endl;

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

  loadComponents();
  loadSystems();

  BaseComponent *transform = swimComponents["Transform"]->create();
  BaseComponent *controls = swimComponents["Controls"]->create();
  BaseComponent *motion = swimComponents["Motion"]->create();

  components.push_back(transform);
  components.push_back(controls);
  components.push_back(motion);

  SwimEntity *entity = new SwimEntity();
  entity->subscribe("removeComponent", [this](EventManager *entity) {
    std::cout << "Remove Component" << std::endl;
    checkEntitySystems(reinterpret_cast<SwimEntity *>(entity));
  });
  entity->subscribe("addComponent", [this](EventManager *entity) {
    std::cout << "Add Component" << std::endl;
    checkEntitySystems(reinterpret_cast<SwimEntity *>(entity));
  });
  entity->addComponent(transform);
  entity->addComponent(controls);
  entity->addComponent(motion);
  // entity->removeComponent(controls->getType());

  entities.push_back(entity);

  running = true;
  std::cout << "Initialized" << std::endl;
  return running;
}

void SwimGame::checkEntitySystems(SwimEntity *entity) {
  std::cout << "checkEntitySystems" << std::endl;
  for (auto &s : systems) {
    s->removeEntity(entity);

    auto reqComp = s->requiredComponents();
    if (reqComp.size() == 0) {
      continue;
    }

    if (std::all_of(reqComp.cbegin(), reqComp.cend(), [entity](auto type) {
          return entity->getComponent(*type) != nullptr;
        })) {
      s->addEntity(entity);
    }
  }
}

void SwimGame::update() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    }
  }

  for (auto &s : systems) {
    s->update();
  }

  auto it = std::remove_if(
      components.begin(), components.end(),
      [](BaseComponent *component) { return !component->isActive(); });
  components.erase(it, components.end());
}

void SwimGame::render() {
  /* Clear screen */
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  /* Draw to window and loop */
  SDL_RenderPresent(renderer);
}

void SwimGame::quit() {
  /* Release resources */
  if (renderer) {
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
  }
  if (window) {
    SDL_DestroyWindow(window);
    window = NULL;
  }

  for (auto &e : entities) {
    delete e;
  }

  for (auto &c : components) {
    delete c;
  }

  for (auto &s : systems) {
    delete s;
  }

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
}
