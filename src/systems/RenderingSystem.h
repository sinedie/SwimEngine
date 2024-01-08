#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include <BaseSwimSystem.h>
#include <Transform.h>

class RenderingSystem : public BaseSwimSystem {
public:
  virtual void init() override;
  virtual void update() override;
};

extern "C" BaseSwimSystem *createSystem() { return new RenderingSystem(); };

#endif
