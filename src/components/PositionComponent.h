#ifndef POSITION_COMPONENT_H
#define POSITION_COMPONENT_H

#include <BaseComponent.h>

class Position : BaseComponent {
private:
  int x = 10;
  int y = 0;

public:
  const std::type_info *getType() override { return &typeid(Position); }
  int getX() { return x; }
};

extern "C" Position *createComponent() { return new Position(); };

#endif
