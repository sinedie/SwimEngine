#ifndef SWIM_ENTITY_H
#define SWIM_ENTITY_H

#include "BaseComponent.h"
#include <EventManager.h>
#include <algorithm>
#include <iostream>
#include <vector>

class SwimEntity : public EventManager {
protected:
  std::vector<BaseComponent *> components;

public:
  void addComponent(BaseComponent *component) {
    components.push_back(component);
    notify("addComponent");
  }

  void removeComponent(const std::type_info *type) {
    auto it = std::remove_if(components.begin(), components.end(),
                             [type](BaseComponent *component) {
                               return *(component->getType()) == *type;
                             });

    if (it == std::end(components)) {
      std::cout << "DEL: Component not found" << std::endl;
      return;
    }

    (*it)->setActive(false);

    components.erase(it, components.end());
    notify("removeComponent");
  }

  std::vector<BaseComponent *> getComponents() { return components; }

  BaseComponent *getComponent(const std::type_info &type) {
    std::vector<BaseComponent *>::iterator it =
        std::find_if(components.begin(), components.end(),
                     [&type](BaseComponent *component) {
                       return *(component->getType()) == type;
                     });

    if (it == std::end(components)) {
      std::cout << "GET: Component not found" << std::endl;
      return nullptr;
    }

    return *it;
  }

  //   ~SwimEntity() {
  //     for (auto &c : components) {
  //       delete c;
  //     }
  //   }
};

#endif
