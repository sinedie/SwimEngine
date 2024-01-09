#include <MotionSystem.h>

void MotionSystem::init() { std::cout << "Init motion system" << std::endl; };

void MotionSystem::update() {
  for (auto &e : entities) {
    Motion *motion =
        reinterpret_cast<Motion *>(e->getComponent(typeid(Motion)));
    Transform *transform =
        reinterpret_cast<Transform *>(e->getComponent(typeid(Transform)));

    transform->position += motion->velocity;
  }
};
