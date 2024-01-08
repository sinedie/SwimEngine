#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include <BaseComponent.h>
#include <Vector2D.h>

class Transform : BaseComponent {
public:
  Vector2D<float> position;
  Vector2D<float> scale;
  float rotation = 0;

  const std::type_info *getType() override { return &typeid(Transform); }
};

extern "C" Transform *createComponent() { return new Transform(); };

#endif
