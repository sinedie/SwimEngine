#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include <BaseComponent.h>
#include <BaseSwimSystem.h>
#include <PositionComponent.h>

class TestSystem : public BaseSwimSystem {
public:
  virtual void init() override;
  virtual void test(BaseComponent *component) override;
};

extern "C" BaseSwimSystem *createSystem() { return new TestSystem(); };

#endif
