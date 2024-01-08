#ifndef BASE_SWIM_SYSTEM_H
#define BASE_SWIM_SYSTEM_H

#include <SwimEntity.h>
#include <iostream>
#include <vector>

class BaseSwimSystem {
protected:
  std::vector<SwimEntity *> entities;

public:
  virtual void init() = 0;

  void addEntity(SwimEntity *entity) { entities.push_back(entity); }

  void removeEntity(SwimEntity *entity) {
    std::remove_if(entities.begin(), entities.end(),
                   [entity](SwimEntity *e) { return e == entity; });
  }

  virtual void update() = 0;
};

#endif
