#ifndef MOTION_SYSTEM_H
#define MOTION_SYSTEM_H

#include <BaseSwimSystem.h>
#include <Motion.h>
#include <Transform.h>

class MotionSystem : public BaseSwimSystem {

public:
  virtual void init() override;
  virtual void update() override;
  virtual std::vector<const std::type_info *> requiredComponents() override {
    return std::vector{&typeid(Transform), &typeid(Motion)};
  };
};

extern "C" BaseSwimSystem *createSystem() { return new MotionSystem(); };

#endif
