#ifndef CONTROLS_COMPONENT_H
#define CONTROLS_COMPONENT_H

#include <BaseComponent.h>

class Controls : BaseComponent {
public:
  const std::type_info *getType() override { return &typeid(Controls); }
};

#endif
