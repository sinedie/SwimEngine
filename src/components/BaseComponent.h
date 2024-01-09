#ifndef BASE_SWIM_COMPONENT_H
#define BASE_SWIM_COMPONENT_H

#include <typeinfo>

class BaseComponent {
protected:
  bool active = true;

public:
  bool isActive() { return active; }
  void setActive(bool active) { this->active = active; }
  virtual const std::type_info *getType() = 0;
};

#endif
