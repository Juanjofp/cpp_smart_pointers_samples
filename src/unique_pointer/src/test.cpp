#include "test.h"

#include <iostream>

using std::cout;

unique_pointer::Test::Test(const char *name) : name{name} {
  cout << "Test for element: " << name << " in " << this << std::endl;
}

void unique_pointer::Test::print_me() const {
  cout << "I'm Element: " << name << " in " << this << std::endl;
}

unique_pointer::Test::~Test() {
  cout << "~Test for element: " << name << " in " << this << std::endl;
}
