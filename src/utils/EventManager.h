#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <algorithm>
#include <functional>
#include <map>
#include <string>
#include <vector>

class EventManager {
  std::map<std::string, std::vector<std::function<void(EventManager *)>>>
      listeners;

public:
  void subscribe(std::string eventType,
                 std::function<void(EventManager *)> func);
  void unsubscribe(std::string eventType,
                   std::function<void(EventManager *)> func);
  void notify(std::string eventType);
  virtual ~EventManager() = default;
};

#endif
