#include <EventManager.h>
#include <iostream>
#include <stdio.h>

void EventManager::subscribe(std::string eventType,
                             std::function<void(EventManager *)> func) {
  std::cout << "Subscribe: " << eventType << std::endl;
  listeners[eventType].push_back(func);
}

void EventManager::unsubscribe(std::string eventType,
                               std::function<void(EventManager *)> func) {
  std::cout << "Unsubscribe: " << eventType << std::endl;

  // auto it = std::remove_if(
  //     listeners[eventType].begin(), listeners[eventType].end(),
  //     [func](std::function<void(EventManager *)> *f) { return f == &func; });

  // listeners[eventType].erase(it, listeners[eventType].end());
}

void EventManager::notify(std::string eventType) {
  for (auto func : listeners[eventType]) {
    func(this);
  }
}
