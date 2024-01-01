#ifndef TEST_SYSTEM_H
#define TEST_SYSTEM_H

#include <BaseSwimSystem.h>

class TestSystem : public BaseSwimSystem {
public:
  virtual void init() override;
};

extern "C" BaseSwimSystem *createSystem() { return new TestSystem(); };

#endif
