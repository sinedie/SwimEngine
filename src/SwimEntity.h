#ifndef SWIM_ENTITY_H
#define SWIM_ENTITY_H

#include "BaseComponent.h"
#include <algorithm>
#include <iostream>
#include <vector>

class SwimEntity {
protected:
  std::vector<BaseComponent *> components;

public:
  void addComponent(BaseComponent *component) {
    components.push_back(component);
  }

  void removeComponent(const std::type_info &type) {
    std::remove_if(components.begin(), components.end(),
                   [&type](BaseComponent *component) {
                     return *(component->getType()) == type;
                   });
  }

  std::vector<BaseComponent *> getComponents() { return components; }

  BaseComponent *getComponent(const std::type_info &type) {
    std::vector<BaseComponent *>::iterator it =
        std::find_if(components.begin(), components.end(),
                     [&type](BaseComponent *component) {
                       return *(component->getType()) == type;
                     });

    if (it == std::end(components)) {
      std::cout << "NOT FOUND" << std::endl;
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
