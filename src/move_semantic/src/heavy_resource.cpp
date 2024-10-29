#include "heavy_resource.h"

#include <cstring>
#include <iostream>

move_semantic::HeavyResource::HeavyResource(const char* name) {
  data = new char[1000000];

  strcpy(data, name);

  std::cout << "HeavyResource constructor" << std::endl;
}

move_semantic::HeavyResource::~HeavyResource() {
  delete[] data;

  data = nullptr;

  std::cout << "HeavyResource destructor" << std::endl;
}

move_semantic::HeavyResource::HeavyResource(const HeavyResource& other) {
  data = new char[1000000];

  strcpy(data, other.data);

  std::cout << "HeavyResource copy constructor" << std::endl;
}

move_semantic::HeavyResource& move_semantic::HeavyResource::operator=(
    const HeavyResource& other) {
  if (this == &other) {
    return *this;
  }

  delete[] data;

  data = new char[1000000];

  strcpy(data, other.data);

  std::cout << "HeavyResource copy assignment operator" << std::endl;

  return *this;
}
