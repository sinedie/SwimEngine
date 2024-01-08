#include <ControlsSystem.h>

void ControlsSystem::init() {
  std::cout << "Init rendering system" << std::endl;
};

void ControlsSystem::update() {
  for (auto &e : entities) {
    Transform *transform =
        reinterpret_cast<Transform *>(e->getComponent(typeid(Transform)));
    transform->position.x += 10;
  }
};
