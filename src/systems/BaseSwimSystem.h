#ifndef BASE_SWIM_SYSTEM_H
#define BASE_SWIM_SYSTEM_H

#include <iostream>

class BaseSwimSystem {
public:
  virtual void init() = 0;
  virtual void test(BaseComponent *component) = 0;
};

#endif
