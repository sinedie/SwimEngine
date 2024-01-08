#include <TestSystem.h>

void TestSystem::init() { std::cout << "FROM LIBRARY TEST" << std::endl; };
void TestSystem::test(BaseComponent *component) {
  std::cout << "a1" << std::endl;
  Position *pos = reinterpret_cast<Position *>(component);
  std::cout << "a2" << std::endl;
  // std::cout << pos << std::endl;
  std::cout << pos->getX() << std::endl;
};
