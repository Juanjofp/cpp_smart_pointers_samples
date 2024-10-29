#pragma once

#include <memory>

#include "test.h"

using std::unique_ptr;

namespace unique_pointer {

class UniqueContainer {
 public:
  explicit UniqueContainer(unique_ptr<Test>& test);
  explicit UniqueContainer(Test* test);
  ~UniqueContainer();

 private:
  unique_ptr<Test> test_ptr;
};

}  // namespace unique_pointer