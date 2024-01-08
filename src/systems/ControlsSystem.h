#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include <BaseSwimSystem.h>
#include <Controls.h>
#include <Transform.h>

class ControlsSystem : public BaseSwimSystem {

public:
  virtual void init() override;
  virtual void update() override;
  virtual std::vector<const std::type_info *> requiredComponents() override {
    return std::vector{&typeid(Transform), &typeid(Controls)};
  };
};

extern "C" BaseSwimSystem *createSystem() { return new ControlsSystem(); };

#endif
