#include "resource_manager.h"

#include <iostream>

move_semantic::ResourceManager::ResourceManager(const char* name)
    : name(name), resource(new HeavyResource(name)) {
  std::cout << "ResourceManager constructor" << std::endl;
}

move_semantic::ResourceManager::~ResourceManager() {
  delete resource;

  resource = nullptr;

  std::cout << "ResourceManager destructor" << std::endl;
}

move_semantic::ResourceManager::ResourceManager(const ResourceManager& other) {
  resource = new HeavyResource{*other.resource};

  name = other.name;

  std::cout << "ResourceManager copy constructor" << std::endl;
}

move_semantic::ResourceManager& move_semantic::ResourceManager::operator=(
    const ResourceManager& other) {
  if (this == &other) {
    return *this;
  }

  delete resource;

  resource = new HeavyResource{*other.resource};

  name = other.name;

  std::cout << "ResourceManager copy assignment operator" << std::endl;

  return *this;
}

move_semantic::ResourceManager::ResourceManager(
    ResourceManager&& other) noexcept
    : resource{other.resource}, name{std::move(other.name)} {
  other.resource = nullptr;

  std::cout << "ResourceManager move constructor" << std::endl;
}

move_semantic::ResourceManager& move_semantic::ResourceManager::operator=(
    ResourceManager&& other) noexcept {
  if (this == &other) {
    return *this;
  }

  delete resource;

  resource = other.resource;

  name = std::move(other.name);

  other.resource = nullptr;

  std::cout << "ResourceManager move assignment operator" << std::endl;

  return *this;
}

std::string move_semantic::ResourceManager::get_name() const { return name; }
