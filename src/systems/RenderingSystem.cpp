#include <RenderingSystem.h>

void RenderingSystem::init() {
  std::cout << "Init rendering system" << std::endl;
};

void RenderingSystem::update() {
  for (auto &e : entities) {
    Transform *transform =
        reinterpret_cast<Transform *>(e->getComponent(typeid(Transform)));
    std::cout << transform->position.x << std::endl;
  }
};
