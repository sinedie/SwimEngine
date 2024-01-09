#ifndef RENDERING_SYSTEM_H
#define RENDERING_SYSTEM_H

#include <BaseSwimSystem.h>
#include <Transform.h>

class RenderingSystem : public BaseSwimSystem {
public:
  virtual void init() override;
  virtual void update() override;
  virtual std::vector<const std::type_info *> requiredComponents() override {
    return std::vector{&typeid(Transform)};
  };
};

extern "C" BaseSwimSystem *createSystem() { return new RenderingSystem(); };

#endif
