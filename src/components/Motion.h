#ifndef MOTION_COMPONENT_H
#define MOTION_COMPONENT_H

#include <BaseComponent.h>
#include <Vector2D.h>

class Motion : BaseComponent {
public:
  Vector2D<float> velocity;
  Vector2D<float> speed = Vector2D<float>(10.0, 20.0);

  const std::type_info *getType() override { return &typeid(Motion); }
};

#endif
