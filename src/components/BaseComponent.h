#ifndef BASE_SWIM_COMPONENT_H
#define BASE_SWIM_COMPONENT_H

#include <typeinfo>

class BaseComponent {
public:
  virtual const std::type_info *getType() = 0;
};

#endif
