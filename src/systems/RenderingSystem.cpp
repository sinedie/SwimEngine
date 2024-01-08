#include <RenderingSystem.h>

void RenderingSystem::init() {
  std::cout << "Init rendering system" << std::endl;
};

void RenderingSystem::update(BaseComponent *component) {
  Transform *transform = reinterpret_cast<Transform *>(component);
  std::cout << transform->position.x << std::endl;
};
