#ifndef CONTROLS_SYSTEM_H
#define CONTROLS_SYSTEM_H

#include <BaseSwimSystem.h>
#include <Controls.h>
#include <Motion.h>
#include <SDL2/SDL.h>

class ControlsSystem : public BaseSwimSystem {

public:
  virtual void init() override;
  virtual void update() override;
  virtual std::vector<const std::type_info *> requiredComponents() override {
    return std::vector{&typeid(Motion), &typeid(Controls)};
  };
};

extern "C" BaseSwimSystem *createSystem() { return new ControlsSystem(); };

#endif
