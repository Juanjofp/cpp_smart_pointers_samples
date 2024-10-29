#pragma once
#include <string>

using std::string;

namespace unique_pointer {

class Test {
 public:
  Test(const char *name = "Test");
  void print_me() const;
  ~Test();

 private:
  string name;
};

}  // namespace unique_pointer